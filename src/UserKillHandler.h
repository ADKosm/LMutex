//
// Created by alex on 30.10.16.
//

#ifndef LMUTEX_USERKILLHANDLER_H
#define LMUTEX_USERKILLHANDLER_H

#include "Handler.h"

class UserKillHandler : public Handler {

public:
    UserKillHandler();

    virtual ~UserKillHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_USERKILLHANDLER_H
