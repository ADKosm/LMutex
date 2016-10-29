//
// Created by alex on 25.10.16.
//
#include <iostream>

#include "LMutex.h"
#include "Message.h"
#include "MessageBuilder.h"
#include "Events.h"
#include "EventsQueue.h"
#include "UserWorker.h"
#include "StressWorker.h"

#include "RequestHandler.h"
#include "ReplyHandler.h"
#include "ReleaseHandler.h"

LMutex::LMutex() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();

    time = 0;
    isSenderFinish = false;
}

LMutex::~LMutex() {
}

void LMutex::lock() {
    Message requestToLock = MessageBuilder()
            .type(Events::Request)
            .id(configuration->Id())
            .time(time)
            .build();
    queue.push(requestToLock);

    manager->sendToAll(requestToLock, this);

    while (!isAllNodesReplyed()) {
        manager->NetEvents()->handle(this);
    }
    replies.clear();

    while (!meOnTop()) {
        manager->NetEvents()->handle(this);
    }
}

void LMutex::unlock() {
    queue.pop();

    Message requestToRelease = MessageBuilder()
            .type(Events::Release)
            .id(configuration->Id())
            .time(time)
            .build();

    manager->sendToAll(requestToRelease, this);
}


bool LMutex::isAllNodesReplyed() {
    return (configuration->Nodes().size() - 1) == replies.size();
}

bool LMutex::meOnTop() {
    return queue.top().id == configuration->Id();
}

bool LMutex::isAllNodesTerminated() {
    return (configuration->Nodes().size()-1) == terminated.size();
}

void LMutex::tick() {
//    std::cout << time << std::endl;
    time++;
}

bool LMutex::isAllNodesReplyOnTerminate() {
    return (configuration->Nodes().size()-1) == terminatedReplies.size();
}

void LMutex::finish() {
    Message terminatedMessage = MessageBuilder()
            .time(this->time)
            .type(Events::Terminate)
            .id(configuration->Id())
            .build();

    manager->sendToAll(terminatedMessage, this);

    while(!isAllNodesReplyOnTerminate()) {
        manager->NetEvents()->handle(this);
    }

    std::cout << "Term size: " << terminatedReplies.size() << std::endl;

    while(!isAllNodesTerminated()) {
        manager->NetEvents()->handle(this);
    }

    manager->finishNetwork();



    while(!isSenderFinish) {
        manager->NetEvents()->handle(this);
    }

    std::cout << "Nodes size: " << terminated.size() << std::endl;
    std::cout << "End my("<< configuration->Id() <<") work" << std::endl;
}