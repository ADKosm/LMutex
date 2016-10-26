//
// Created by alex on 25.10.16.
//

#include "Handler.h"
#include "LMutex.h"
#include "NetManager.h"
#include "Configuration.h"

Handler::Handler() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();
}

Handler::~Handler() {
    delete manager;
    delete configuration;
}

