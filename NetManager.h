//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_NETMANAGER_H
#define LMUTEX_NETMANAGER_H

#include "Listener.h"
#include "EventsQueue.h"
#include "SafeQueue.h"

#include <cstdint>

class Sender;

class NetManager {
    friend class Sender;
public:
    static NetManager * Inst() {
        if(!self) self = new NetManager();
        return self;
    }

    void init();
    void run();

    EventsQueue * NetEvents();
    EventsQueue * UserEvents();

    void sendTo(std::uint32_t id, Message message, LMutex *mutex);
    void sendToAll(Message message, LMutex *mutex);

private:
    NetManager();
    ~NetManager();

    static NetManager * self;

    int argv;
    char ** argc;

    Listener * listener;
    Sender * sender;

    EventsQueue * netEvents;
    EventsQueue * userEvents;

    SafeQueue< std::pair<std::uint32_t , Message> >messagesToSend;
};

NetManager * NetManager::self = nullptr;


#endif //LMUTEX_NETMANAGER_H
