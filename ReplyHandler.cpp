//
// Created by alex on 25.10.16.
//

#include "ReplyHandler.h"
#include "NetManager.h"
#include "Configuration.h"
#include "MessageBuilder.h"
#include "Events.h"


ReplyHandler::ReplyHandler() : Handler() {
}

ReplyHandler::~ReplyHandler() {
}

void ReplyHandler::handle(Message message, LMutex *mutex) {
    mutex->replies.insert(message);
    mutex->tick();
}