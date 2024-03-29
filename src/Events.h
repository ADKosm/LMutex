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

    static std::uint8_t Terminate;
    static std::uint8_t TerminateReply;

    static std::uint8_t Acquire;

    static std::uint8_t UserLock;
    static std::uint8_t UserUnlock;
    static std::uint8_t UserKill;
};

#endif //LMUTEX_EVENTS_H
