#pragma once

#include <algorithm>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include "broker/message.hpp"

struct Subscriber;
struct Broker
{
    auto subscribe(std::string topic, Subscriber *subscriber) -> void
    {
        subscriptions[topic].push_back(subscriber);
    }

    template <typename... T>
    auto publish(std::string topic, T &&...payload)
    {
        auto sharable_message = std::make_shared<MessagePayload<T...>>(topic, std::forward<T>(payload)...);
        std::ranges::for_each(subscriptions[topic], [sharable_message](auto *subscriber)
                              { subscriber->receive(sharable_message); });
    }

    std::unordered_map<std::string, std::vector<Subscriber *>>
        subscriptions;
};
