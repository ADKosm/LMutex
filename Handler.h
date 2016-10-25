//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_HANDLER_H
#define LMUTEX_HANDLER_H

#include "LMutex.h"
#include "Message.h"

class Handler {
public:
    Handler();
    virtual ~Handler();

    virtual void handle(Message message, LMutex *mutex) = 0;

protected:
    NetManager *manager;
    Configuration *configuration;
};


#endif //LMUTEX_HANDLER_H
