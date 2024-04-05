#pragma once

#include <string>
#include <tuple>

struct Message
{
    Message(std::string topic_)
        : topic{topic_}
    {
    }
    virtual ~Message() = default;
    std::string topic;
};

template <typename... T>
struct MessagePayload : Message
{
    MessagePayload(std::string topic_, T... payload_)
        : Message{topic_},
          payload{std::make_tuple(payload_...)}
    {
    }

    std::tuple<T...> payload;
};
