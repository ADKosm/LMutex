//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_MESSAGE_H
#define LMUTEX_MESSAGE_H

#include <cstdint>

struct Message {
    std::uint8_t type;
    std::uint32_t id;
    std::uint64_t time;
};


#endif //LMUTEX_MESSAGE_H
