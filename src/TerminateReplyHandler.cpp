//
// Created by alex on 29.10.16.
//

#include <iostream>
#include "TerminateReplyHandler.h"
#include "LMutex.h"

TerminateReplyHandler::TerminateReplyHandler() : Handler() {

}

TerminateReplyHandler::~TerminateReplyHandler() {

}

void TerminateReplyHandler::handle(Message message, LMutex *mutex) {
    std::cout << "Receive TermReply from " << message.id << std::endl;

    mutex->terminatedReplies.insert(message);
    mutex->time = std::max(mutex->time, message.time) + 1;
}

