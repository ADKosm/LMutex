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
    std::cout << "Reveive release message" << std::endl;
    if(mutex->queue.top().id == message.id) {
        mutex->queue.pop();
        mutex->time = std::max(message.time, mutex->time) + 1;
    } else {
        throw std::string("Release error");
    }
}

