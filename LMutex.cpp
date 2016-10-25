//
// Created by alex on 25.10.16.
//

#include "LMutex.h"
#include "Message.h"
#include "MessageBuilder.h"
#include "Events.h"
#include "EventsQueue.h"

LMutex::LMutex() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();

    time = 0;
}

LMutex::~LMutex() {
}

void LMutex::lock() {
    Message requestToLock = MessageBuilder()
            .type(Events::Request)
            .id(configuration->Id())
            .time(time)
            .build();
    queue.push(requestToLock);

    manager->sendToAll(requestToLock, nullptr);

    while (!isAllNodesReplyed()) {
        manager->NetEvents()->handle(this);
    }
    replies.clear();

    while (!meOnTop()) {
        manager->NetEvents()->handle(this);
    }
}

void LMutex::unlock() {
    queue.pop();

    Message requestToRelease = MessageBuilder()
            .type(Events::Release)
            .id(configuration->Id())
            .time(time)
            .build();

    manager->sendToAll(requestToRelease, this);
}


bool LMutex::isAllNodesReplyed() {
    return configuration->Nodes().size() == replies.size();
}

bool LMutex::meOnTop() {
    return queue.top().id == configuration->Id();
}

void LMutex::tick() {
    time++;
}