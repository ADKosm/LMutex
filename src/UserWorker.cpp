//
// Created by alex on 25.10.16.
//

#include "UserWorker.h"
#include "LMutex.h"

UserWorker::UserWorker() : Worker() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();
}

UserWorker::~UserWorker() {

}

void UserWorker::run() {
    LMutex mutex;

    for(;;) {
        while(!configuration->isUserLock()) manager->NetEvents()->handle(&mutex);

        mutex.lock();

        writeToFile(mutex);

        while(!configuration->isUserUnlock()) manager->NetEvents()->handle(&mutex);

        mutex.unlock();

    }
}

