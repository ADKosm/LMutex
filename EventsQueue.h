//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_EVENTSQUEUE_H
#define LMUTEX_EVENTSQUEUE_H

#include <queue>
#include <mutex>
#include <map>
#include <condition_variable>
#include <cstdint>

#include "Message.h"
#include "Events.h"
#include "LMutex.h"
#include "Handler.h"
#include "SafeQueue.h"

class EventsQueue {
public:
    EventsQueue();
    ~EventsQueue();

    void push(const Message& message);

    void handle(LMutex *lmutex);

private:
    SafeQueue<Message> queue;
    std::map< std::uint8_t , Handler * > handlers;
};


#endif //LMUTEX_EVENTSQUEUE_H
