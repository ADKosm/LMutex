//
// Created by alex on 25.10.16.
//

#include "RequestHandler.h"
#include "MessageBuilder.h"
#include "Events.h"
#include "Configuration.h"

RequestHandler::RequestHandler() : Handler() {
}

RequestHandler::~RequestHandler() {
}

void RequestHandler::handle(Message message, LMutex *mutex) {
    mutex->queue.push(message);
    mutex->time = std::max(mutex->time, message.time) + 1;

    Message reply = MessageBuilder()
            .type(Events::Reply)
            .id(configuration->Id())
            .time(mutex->time)
            .build();

    manager->sendToAll(reply, mutex);
}

