//
// Created by alex on 25.10.16.
//

#include "NetManager.h"
#include "Configuration.h"
#include "Sender.h"
#include "LMutex.h"
#include "EventsQueue.h"

#include <thread>

void NetManager::run() {
    std::thread([this](){
        this->sender->run();
    }).detach();

    std::thread([this](){
        this->listener->run();
    }).detach();
}

void NetManager::init() {
}

NetManager::NetManager() {
    listener = new Listener();
    sender = new Sender();
}

NetManager::~NetManager() {
    delete listener;
    delete sender;
}

EventsQueue *NetManager::NetEvents() {
    return netEvents;
}

EventsQueue *NetManager::UserEvents() {
    return userEvents;
}

void NetManager::sendTo(std::uint32_t id, Message message, LMutex *mutex) {
    mutex->tick();
    messagesToSend.push(std::make_pair(id, message));
}

void NetManager::sendToAll(Message message, LMutex *mutex) {
    auto& nodes = Configuration::Inst()->Nodes();
    for(auto e : nodes) {
        sendTo(e.first, message, mutex);
    }
}

