//
// Created by alex on 30.10.16.
//

#include "TestNetManager.h"
#include "../src/LMutex.h"
#include "../src/Message.h"

void TestNetManager::init() {
    std::unique_lock<std::mutex> lock(initMutex);

    events[Configuration::Inst()->Id()] = new EventsQueue();
}

void TestNetManager::run() {
}

EventsQueue *TestNetManager::NetEvents() {
    return events[Configuration::Inst()->Id()];
}

EventsQueue *TestNetManager::UserEvents() {
    return NetManager::UserEvents();
}

void TestNetManager::sendTo(std::uint32_t id, Message message, LMutex *mutex) {
    std::unique_lock<std::mutex> lock(pushMutex);
    mutex->tick();
    events[id]->push(message);
}

void TestNetManager::sendToAll(Message message, LMutex *mutex) {
    auto& nodes = Configuration::Inst()->Nodes();
    mutex->tick();
    for(auto e: nodes) {
        mutex->tick();
        if(e.first != Configuration::Inst()->Id()) sendTo(e.first, message, mutex);
    }
}

TestNetManager::~TestNetManager() {
    for(auto i : events) {
        delete i.second;
    }
}


TestNetManager::TestNetManager() {

}

