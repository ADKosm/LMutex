//
// Created by alex on 25.10.16.
//

#include <iostream>
#include "ReplyHandler.h"
#include "NetManager.h"
#include "Configuration.h"
#include "MessageBuilder.h"
#include "Events.h"
#include "LMutex.h"


ReplyHandler::ReplyHandler() : Handler() {
}

ReplyHandler::~ReplyHandler() {
}

void ReplyHandler::handle(Message message, LMutex *mutex) {
    std::cout << "["<< configuration->Id() <<"]Receive reply message from " << message.id << "("<< message.time <<")" << std::endl;
    mutex->replies.insert(message);
    mutex->time = std::max(mutex->time, message.time) + 1;
}