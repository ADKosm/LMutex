//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_LISTENER_H
#define LMUTEX_LISTENER_H

#include "Configuration.h"

class NetManager;

class Listener {
public:
    Listener();
    ~Listener();

    void run();

private:
    NetManager * manager;
    Configuration * configuration;
};


#endif //LMUTEX_LISTENER_H
