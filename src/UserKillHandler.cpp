//
// Created by alex on 30.10.16.
//

#include "UserKillHandler.h"
#include "Configuration.h"

UserKillHandler::UserKillHandler() : Handler() {

}

UserKillHandler::~UserKillHandler() {

}

void UserKillHandler::handle(Message message, LMutex *mutex) {
    exit(0);
}

