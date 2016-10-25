//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_LMUTEX_H
#define LMUTEX_LMUTEX_H

#include <cstdint>
#include <queue>
#include <vector>
#include <set>

#include "RequestHandler.h"
#include "ReplyHandler.h"
#include "ReleaseHandler.h"
#include "NetManager.h"
#include "Configuration.h"

class qComparator {
public:
    qComparator() {}
    ~qComparator() {}

    bool operator() (const Message& a, const Message& b) const {
        if(a.time == b.time) {
            return a.id < b.id;
        }
        return a.time < b.time;
    }
};

class replyComparator {
public:
    replyComparator() {}
    ~replyComparator() {}

    bool operator() (const Message& a, const Message& b) const {
        return a.id < b.id;
    }
};

class LMutex {
    friend class RequestHandler;
    friend class ReplyHandler;
    friend class ReleaseHandler;
public:
    LMutex();
    ~LMutex();

    void lock();
    void unlock();

    void tick();

private:
    std::uint64_t time;
    std::priority_queue<Message, std::vector<Message>, qComparator > queue;
    std::set<Message, replyComparator> replies;
    NetManager * manager;
    Configuration * configuration;

    bool meOnTop();
    bool isAllNodesReplyed();
};


#endif //LMUTEX_LMUTEX_H
