//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_USERWORKER_H
#define LMUTEX_USERWORKER_H

#include "Worker.h"

class UserWorker : public Worker {

public:
    UserWorker();

    virtual ~UserWorker() override;

    virtual void run() override;
};


#endif //LMUTEX_USERWORKER_H