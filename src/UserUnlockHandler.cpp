//
// Created by alex on 30.10.16.
//

#include "UserUnlockHandler.h"
#include "Configuration.h"

UserUnlockHandler::UserUnlockHandler() : Handler() {

}

UserUnlockHandler::~UserUnlockHandler() {

}

void UserUnlockHandler::handle(Message message, LMutex *mutex) {
    configuration->setUserUnlock(true);
}