//
// Created by alex on 29.10.16.
//

#ifndef LMUTEX_TERMINATEREPLYHANDLER_H
#define LMUTEX_TERMINATEREPLYHANDLER_H

#include "Handler.h"

class TerminateReplyHandler : public Handler {

public:
    TerminateReplyHandler();

    virtual ~TerminateReplyHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_TERMINATEREPLYHANDLER_H
