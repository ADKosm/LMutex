//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_REQUESTHANDLER_H
#define LMUTEX_REQUESTHANDLER_H

#include "Handler.h"
#include "NetManager.h"

class RequestHandler : public Handler {
public:
    RequestHandler();

    virtual ~RequestHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_REQUESTHANDLER_H
