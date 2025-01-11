#pragma once

#include <fmt/format.h>

#include <array>
#include <chrono>
#include <functional>
#include <mutex>
#include <optional>
#include <queue>
#include <thread>

namespace toadofsky
{
    struct Task
    {
        std::chrono::time_point<std::chrono::high_resolution_clock> time = std::chrono::high_resolution_clock::now();
        std::function<void(void)> function;

        auto operator()() -> void
        {
            function();
        }
    };

    static auto operator<(const Task &t1, const Task &t2) -> bool
    {
        return t1.time > t2.time;
    }

    template <std::size_t N>
    struct ThreadPool
    {
        ThreadPool()
        {
            threads.reserve(N);
            for (auto i = std::size_t{}; i < N; ++i)
            {
                threads.emplace_back(std::bind_front(&ThreadPool::process, this));
            }
        }

        ~ThreadPool()
        {
            for (auto &thread : threads)
            {
                thread.request_stop();
            }
        }

        auto schedule(Task &&task)
        {
            auto lock = std::lock_guard(task_mutex);
            task_queue.push(std::move(task));
        }

        auto get_task() -> std::optional<Task>
        {
            auto lock = std::lock_guard(task_mutex);
            time = std::chrono::high_resolution_clock::now();
            if (task_queue.empty())
            {
                return std::nullopt;
            }

            auto task = task_queue.top();
            if (task.time < time)
            {
                task_queue.pop();
                return task;
            }
            return std::nullopt;
        }

        auto process(std::stop_token stop_token) -> void
        {
            while (!stop_token.stop_requested())
            {
                if (auto task = get_task())
                {
                    task.value()();
                }
            }
        }

        std::vector<std::jthread> threads{};
        std::priority_queue<Task> task_queue{};
        std::mutex task_mutex{};
        std::chrono::time_point<std::chrono::high_resolution_clock> time{std::chrono::high_resolution_clock::now()};
    };
}