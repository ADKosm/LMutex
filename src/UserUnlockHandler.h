//
// Created by alex on 30.10.16.
//

#ifndef LMUTEX_USERUNLOCK_H
#define LMUTEX_USERUNLOCK_H

#include "Handler.h"

class UserUnlockHandler : public Handler {

public:
    UserUnlockHandler();

    virtual ~UserUnlockHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_USERUNLOCK_H
