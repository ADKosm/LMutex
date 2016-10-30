//
// Created by alex on 25.10.16.
//

#include <algorithm>
#include <iostream>
#include "ReleaseHandler.h"
#include "LMutex.h"

ReleaseHandler::ReleaseHandler() : Handler() {
}

ReleaseHandler::~ReleaseHandler() {
}

void ReleaseHandler::handle(Message message, LMutex *mutex) {
    if(mutex->queue.top().id == message.id) {
        mutex->queue.pop();

        releasePrevious(message, mutex);
    } else {
        released.insert(message);
    }
    mutex->time = std::max(message.time, mutex->time) + 1;
}


void ReleaseHandler::releasePrevious(Message message, LMutex *mutex) {
    while( released.count(mutex->queue.top()) > 0 ) {
        released.erase(mutex->queue.top());
        mutex->queue.pop();
    }
}

