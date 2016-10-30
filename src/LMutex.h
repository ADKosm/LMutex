//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_LMUTEX_H
#define LMUTEX_LMUTEX_H

#include <cstdint>
#include <queue>
#include <vector>
#include <set>

#include "NetManager.h"
#include "Configuration.h"
#include "Message.h"
#include "ReplyComparator.h"

class StressWorker;
class UserWorker;

class RequestHandler;
class ReplyHandler;
class ReleaseHandler;
class TerminateHandler;
class TerminateReplyHandler;

class UserLockHandler;
class UserUnlockHandler;
class UserKillHandler;

class qComparator {
public:
    qComparator() {}
    ~qComparator() {}

    bool operator() (const Message& a, const Message& b) const {
        if(a.time == b.time) {
            return a.id > b.id;
        }
        return a.time > b.time;
    }
};

class LMutex {
    friend class RequestHandler;
    friend class ReplyHandler;
    friend class ReleaseHandler;
    friend class TerminateHandler;
    friend class TerminateReplyHandler;

    friend class UserLockHandler;
    friend class UserUnlockHandler;
    friend class UserKillHandler;

    friend class StressWorker;
    friend class UserWorker;
    friend class Worker;
public:
    LMutex();
    ~LMutex();

    void lock();
    void unlock();

    void finish();

    void tick();

private:
    std::uint64_t time;
    std::priority_queue<Message, std::vector<Message>, qComparator > queue;
    std::set<Message, replyComparator> replies;

    std::set<Message, replyComparator> terminated;
    std::set<Message, replyComparator> terminatedReplies;

    NetManager * manager;
    Configuration * configuration;

    bool meOnTop();
    bool isAllNodesReplyed();
    bool isAllNodesTerminated();
    bool isAllNodesReplyOnTerminate();
};


#endif //LMUTEX_LMUTEX_H
