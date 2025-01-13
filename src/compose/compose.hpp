#pragma once

#include "toadofsky/plugin/shared_library.hpp"
#include "toadofsky/module/module.hpp"

#include <functional>
#include <map>
#include <string>

struct Composer
{
    using ModuleT = std::unique_ptr<toadofsky::Module>;

    auto load(const std::filesystem::path &plugin_path)
    {
        plugins.emplace(plugin_path.stem(), toadofsky::DynamicLibrary(plugin_path));
        functions.emplace(plugin_path.stem(), plugins.at(plugin_path.stem()).get_function<ModuleT (*)(void)>("make_test_lib"));
    }

    std::map<std::string, toadofsky::DynamicLibrary> plugins{};
    std::map<std::string, std::function<ModuleT(void)>> functions{};
};