//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_USERWORKER_H
#define LMUTEX_USERWORKER_H

#include "Worker.h"
#include "NetManager.h"
#include "Configuration.h"

class UserWorker : public Worker {

public:
    UserWorker();

    virtual ~UserWorker() override;

    virtual void run() override;

private:
    Configuration * configuration;
    NetManager * manager;
};


#endif //LMUTEX_USERWORKER_H
