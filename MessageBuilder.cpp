//
// Created by alex on 25.10.16.
//

#include "MessageBuilder.h"

MessageBuilder::MessageBuilder() {
}

MessageBuilder::~MessageBuilder() {
}

MessageBuilder &MessageBuilder::id(std::uint32_t id) {
    m.id = id;
    return *this;
}

MessageBuilder &MessageBuilder::type(std::uint8_t type) {
    m.type = type;
    return *this;
}

MessageBuilder &MessageBuilder::time(std::uint64_t time) {
    m.time = time;
    return *this;
}

Message MessageBuilder::build() {
    return m;
}

