//
// Created by alex on 29.10.16.
//

#ifndef LMUTEX_SENDERFINISHHANDLER_H
#define LMUTEX_SENDERFINISHHANDLER_H

#include "Handler.h"

class SenderFinishHandler : public Handler {

public:
    SenderFinishHandler();

    virtual ~SenderFinishHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_SENDERFINISHHANDLER_H
