//
// Created by alex on 30.10.16.
//

#ifndef LMUTEX_TESTNETMANAGER_H
#define LMUTEX_TESTNETMANAGER_H

#include "../src/NetManager.h"
#include "../src/EventsQueue.h"
#include <map>
#include <mutex>
#include <thread>

class TestNetManager : public NetManager {


public:
    TestNetManager();
    virtual void init() override;

    virtual void run() override;

    virtual EventsQueue *NetEvents() override;

    virtual EventsQueue *UserEvents() override;

    virtual void sendTo(std::uint32_t id, Message message, LMutex *mutex) override;

    virtual void sendToAll(Message message, LMutex *mutex) override;

    virtual ~TestNetManager() override;

private:

    std::map<uint32_t , EventsQueue*> events;
    std::mutex initMutex;
    std::mutex pushMutex;
};


#endif //LMUTEX_TESTNETMANAGER_H
