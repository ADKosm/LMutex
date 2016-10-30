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
    std::cout << "["<< configuration->Id() <<"]Reveive release message from " << message.id << "("<< message.time <<")" << std::endl;
    if(mutex->queue.top().id == message.id) {
        mutex->queue.pop();

        releasePrevious(message, mutex);

        mutex->time = std::max(message.time, mutex->time) + 1;
    } else {
        released.insert(message);
//        std::cout << "Release error: " << message.id << std::endl;
//        throw std::string("Release error");
    }
}


void ReleaseHandler::releasePrevious(Message message, LMutex *mutex) {
    while( released.count(mutex->queue.top()) > 0 ) {
        released.erase(mutex->queue.top());
        mutex->queue.pop();
    }
}

