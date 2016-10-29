//
// Created by alex on 29.10.16.
//

#include "TerminateReplyHandler.h"
#include "LMutex.h"

TerminateReplyHandler::TerminateReplyHandler() : Handler() {

}

TerminateReplyHandler::~TerminateReplyHandler() {

}

void TerminateReplyHandler::handle(Message message, LMutex *mutex) {
    mutex->terminatedReplies.insert(message);
    mutex->time = std::max(mutex->time, message.time) + 1;
}

