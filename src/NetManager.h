//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_NETMANAGER_H
#define LMUTEX_NETMANAGER_H

#include "Listener.h"
#include "SafeQueue.h"
#include "EventsQueue.h"

#include <cstdint>

class Sender;
class EventQueue;

class NetManager {
    friend class Sender;
public:
    static NetManager * Inst() {
        if(self == nullptr) self = new NetManager();
        return self;
    }

    virtual void init();
    virtual void run();

    virtual EventsQueue * NetEvents();

    virtual EventsQueue * UserEvents();

    virtual void sendTo(std::uint32_t id, Message message, LMutex *mutex);
    virtual void sendToAll(Message message, LMutex *mutex);

    virtual ~NetManager();

protected:
    NetManager();

    static NetManager * self;

    Listener * listener;
    Sender * sender;

    EventsQueue * netEvents;
    EventsQueue * userEvents;
};


#endif //LMUTEX_NETMANAGER_H
