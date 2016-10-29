//
// Created by alex on 25.10.16.
//

#include <iostream>
#include "RequestHandler.h"
#include "MessageBuilder.h"
#include "Events.h"
#include "Configuration.h"
#include "LMutex.h"

RequestHandler::RequestHandler() : Handler() {
}

RequestHandler::~RequestHandler() {
}

void RequestHandler::handle(Message message, LMutex *mutex) {

    std::cout << "Receive request message" << std::endl;
    mutex->queue.push(message);
    mutex->time = std::max(mutex->time, message.time) + 1;
//    message.time = mutex->time;
//    mutex->queue.push(message);

    Message reply = MessageBuilder()
            .type(Events::Reply)
            .id(configuration->Id())
            .time(mutex->time)
            .build();

    manager->sendTo(message.id, reply, mutex);
}

