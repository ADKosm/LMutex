//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_REPLYHANDLER_H
#define LMUTEX_REPLYHANDLER_H

#include "Handler.h"

class ReplyHandler : public Handler {

public:
    ReplyHandler();

    virtual ~ReplyHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_REPLYHANDLER_H
