//
// Created by alex on 29.10.16.
//

#ifndef LMUTEX_TERMINATEHANDLER_H
#define LMUTEX_TERMINATEHANDLER_H

#include "Handler.h"

class TerminateHandler : public Handler {

public:
    TerminateHandler();

    virtual ~TerminateHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_TERMINATEHANDLER_H
