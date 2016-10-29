//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_USERLOCKHANDLER_H
#define LMUTEX_USERLOCKHANDLER_H

#include "Handler.h"

class UserLockHandler : public Handler {

public:
    UserLockHandler();

    virtual ~UserLockHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_USERLOCKHANDLER_H
