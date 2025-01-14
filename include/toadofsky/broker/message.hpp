#pragma once

#include <memory>
#include <string>
#include <tuple>

namespace toadofsky
{
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

    template <typename... T>
    static inline auto message_cast(std::shared_ptr<Message> message) -> std::shared_ptr<MessagePayload<T...>>
    {
        return std::dynamic_pointer_cast<toadofsky::MessagePayload<T...>>(message);
    }
}
