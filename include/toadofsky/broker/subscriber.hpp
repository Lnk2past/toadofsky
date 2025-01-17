#pragma once

#include "toadofsky/broker/message.hpp"

#include <memory>
#include <mutex>
#include <queue>

namespace toadofsky
{
    struct Subscriber
    {
        virtual ~Subscriber() = default;

        virtual auto receive(std::shared_ptr<Message> message) -> void
        {
            std::lock_guard lk{mutex};
            messages.push_back(message);
        }

        virtual auto get_messages() -> std::vector<std::shared_ptr<Message>>
        {
            std::lock_guard lk{mutex};
            if (messages.empty())
            {
                return {};
            }
            auto m = std::vector<std::shared_ptr<Message>>(
                messages.begin(),
                messages.end());
            messages.clear();
            return m;
        }

        std::vector<std::shared_ptr<Message>> messages{};
        std::mutex mutex;
    };
}
