//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_RELEASEHANDLER_H
#define LMUTEX_RELEASEHANDLER_H

#include "Handler.h"

class ReleaseHandler : public Handler {

public:
    ReleaseHandler();

    virtual ~ReleaseHandler() override;

    virtual void handle(Message message, LMutex *mutex) override;
};


#endif //LMUTEX_RELEASEHANDLER_H
