//
// Created by alex on 25.10.16.
//

#include "EventsQueue.h"
#include "ReleaseHandler.h"
#include "ReplyHandler.h"
#include "RequestHandler.h"
#include "UserLockHandler.h"

EventsQueue::EventsQueue() {
    handlers[Events::Release] = new ReleaseHandler();
    handlers[Events::Reply] = new ReplyHandler();
    handlers[Events::Request] = new RequestHandler();
    handlers[Events::UserLock] = new UserLockHandler();
}

EventsQueue::~EventsQueue() {
    for(auto e : handlers) {
        delete e.second;
    }
}

void EventsQueue::push(const Message &message)  {
    queue.push(message);
}


void EventsQueue::handle(LMutex *lmutex) {
    Message item = queue.pop();
    handlers[item.type]->handle(item, lmutex);
}