//
// Created by alex on 25.10.16.
//

#include "ReleaseHandler.h"

ReleaseHandler::ReleaseHandler() : Handler() {
}

ReleaseHandler::~ReleaseHandler() {
}

void ReleaseHandler::handle(Message message, LMutex *mutex) {
    if(mutex->queue.top().id == message.id) {
        mutex->queue.pop();
        mutex->tick();
    } else {
        throw std::string("Release error");
    }
}

