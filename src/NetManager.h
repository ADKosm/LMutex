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

    void init();
    void run();

    EventsQueue * NetEvents();
    EventsQueue * UserEvents();

    void sendTo(std::uint32_t id, Message message, LMutex *mutex);
    void sendToAll(Message message, LMutex *mutex);

    ~NetManager();
private:
    NetManager();

    static NetManager * self;

    Listener * listener;
    Sender * sender;

    EventsQueue * netEvents;
    EventsQueue * userEvents;
};


#endif //LMUTEX_NETMANAGER_H
