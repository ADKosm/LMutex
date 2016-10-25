//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_EVENTS_H
#define LMUTEX_EVENTS_H

#include <cstdint>

class Events {
public:
    static std::uint8_t Reply;
    static std::uint8_t Release;
    static std::uint8_t Request;
    static std::uint8_t UserLock;
};

std::uint8_t Events::Reply = 0;
std::uint8_t Events::Release = 1;
std::uint8_t Events::Request = 2;
std::uint8_t Events::UserLock = 3;

#endif //LMUTEX_EVENTS_H
