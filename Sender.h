//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_SENDER_H
#define LMUTEX_SENDER_H

#include <cstdint>
#include <map>
#include "Message.h"
#include "Node.h"
#include "Configuration.h"
#include "Logger.h"

class NetManager;

class Sender {
public:
    Sender();
    ~Sender();

    void run();

    void sendTo(std::uint32_t id, Message message);

private:
    std::map< std::uint32_t , Node > nodes;

    NetManager * manager;
    Configuration * configuration;
    Logger * logger;
};


#endif //LMUTEX_SENDER_H
