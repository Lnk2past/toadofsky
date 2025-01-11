#pragma once

#include "toadofsky/broker/message.hpp"

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

namespace toadofsky
{
    struct Subscriber;
    struct Broker
    {
        auto subscribe(std::string topic, Subscriber *subscriber) -> void
        {
            subscriptions[topic].push_back(subscriber);
        }

        template <typename... T>
        auto publish(std::string topic, T... payload)
        {
            auto sharable_message = std::make_shared<MessagePayload<T...>>(topic, payload...);
            std::ranges::for_each(subscriptions[topic], [sharable_message](auto *subscriber)
                                  { subscriber->receive(sharable_message); });
        }

        std::unordered_map<std::string, std::vector<Subscriber *>>
            subscriptions;
    };
}
