//
// Created by alex on 25.10.16.
//

#include "UserLockHandler.h"
#include "LMutex.h"
#include "Configuration.h"

UserLockHandler::UserLockHandler() : Handler() {

}

UserLockHandler::~UserLockHandler() {

}

void UserLockHandler::handle(Message message, LMutex *mutex) {
    configuration->setUserLock(true);
}

