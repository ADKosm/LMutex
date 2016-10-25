//
// Created by alex on 25.10.16.
//

#include "StressWorker.h"
#include "LMutex.h"

StressWorker::StressWorker() :
        number(100)
{}

StressWorker::~StressWorker() {
}

void StressWorker::run() {
    LMutex mutex;
    for(int i = 0; i < number; i++) {
        mutex.lock();
        write();
        mutex.unlock();
    }
}


void StressWorker::write() {
 // TODO: implement this
}