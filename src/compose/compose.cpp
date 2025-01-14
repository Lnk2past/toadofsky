#include "compose.hpp"

#include "toadofsky/broker/broker.hpp"
#include "toadofsky/orchestrator/orchestrator.hpp"

#include <fmt/format.h>
#include <nlohmann/json.hpp>

#include <chrono>
#include <filesystem>
#include <fstream>
#include <thread>

using namespace std::chrono_literals;
using json = nlohmann::json;

auto main(int argc, char **argv) -> int
{
    if (argc == 1)
    {
        return 1;
    }

    auto f = std::ifstream{argv[1]};
    auto config = json::parse(f);

    auto compose = Composer{};
    auto modules = std::vector<std::unique_ptr<toadofsky::Module>>{};
    for (const auto &spec : config["modules"])
    {
        const auto module_path = spec["path"].get<std::filesystem::path>();
        compose.load(module_path);
        for (auto i = 0; i < spec["count"].get<int>(); ++i)
        {
            modules.push_back(compose.functions[module_path.stem()]());
        }
    }

    auto broker = toadofsky::Broker{};
    auto orchestrator = toadofsky::Orchestrator{};

    fmt::println("Registering models...");
    for (auto &module : modules)
    {
        orchestrator.register_model(module.get());
    }

    orchestrator.run(broker);
    std::this_thread::sleep_for(3s);
    fmt::println("Done");
}
