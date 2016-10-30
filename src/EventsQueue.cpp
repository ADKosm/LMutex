//
// Created by alex on 25.10.16.
//

#include "Events.h"
#include "EventsQueue.h"
#include "ReleaseHandler.h"
#include "ReplyHandler.h"
#include "RequestHandler.h"
#include "UserLockHandler.h"
#include "TerminateHandler.h"
#include "TerminateReplyHandler.h"
#include "LMutex.h"

EventsQueue::EventsQueue() {
    handlers[Events::Release] = new ReleaseHandler();
    handlers[Events::Reply] = new ReplyHandler();
    handlers[Events::Request] = new RequestHandler();
    handlers[Events::UserLock] = new UserLockHandler();
    handlers[Events::Terminate] = new TerminateHandler();
    handlers[Events::TerminateReply] = new TerminateReplyHandler();
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