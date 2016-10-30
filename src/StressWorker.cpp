//
// Created by alex on 25.10.16.
//

#include "StressWorker.h"
#include "LMutex.h"
#include "Logger.h"
#include "MessageBuilder.h"
#include <iostream>
#include <thread>
#include <sstream>
#include <chrono>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/file.h>


StressWorker::StressWorker() :
        number(10000)
{}

StressWorker::~StressWorker() {
}

void StressWorker::run() {
    LMutex mutex;
    for(int i = 0; i < number; i++) {
        mutex.lock();
        writeToFile(mutex);
        mutex.unlock();
    }
}
