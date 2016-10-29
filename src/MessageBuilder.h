//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_MESSAGEBUILDER_H
#define LMUTEX_MESSAGEBUILDER_H

#include "Message.h"
#include <cstdint>
#include <string>

class MessageBuilder {
public:
    MessageBuilder();
    ~MessageBuilder();

    MessageBuilder& id(std::uint32_t id);
    MessageBuilder& type(std::uint8_t type);
    MessageBuilder& time(std::uint64_t time);

    Message build();
private:
    Message m;
};


#endif //LMUTEX_MESSAGEBUILDER_H
