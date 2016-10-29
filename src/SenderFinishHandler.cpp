//
// Created by alex on 29.10.16.
//

#include "SenderFinishHandler.h"
#include "LMutex.h"

SenderFinishHandler::SenderFinishHandler() : Handler() {
}

SenderFinishHandler::~SenderFinishHandler() {
}

void SenderFinishHandler::handle(Message message, LMutex *mutex) {
    mutex->isSenderFinish = true;
}

