//
// Created by alex on 29.10.16.
//

#include <iostream>
#include "TerminateHandler.h"
#include "LMutex.h"
#include "MessageBuilder.h"

TerminateHandler::TerminateHandler() : Handler() {
}

TerminateHandler::~TerminateHandler() {
}

void TerminateHandler::handle(Message message, LMutex *mutex) {
    mutex->terminated.insert(message);
    mutex->time = std::max(mutex->time, message.time) + 1;

    Message terminateReply = MessageBuilder()
            .id(configuration->Id())
            .time(mutex->time)
            .type(Events::TerminateReply)
            .build();

    manager->sendTo(message.id, terminateReply, mutex);
}

