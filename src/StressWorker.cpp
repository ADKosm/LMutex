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


void StressWorker::writeToFile(LMutex &mutex) {
    std::stringstream stringBuilder;
    stringBuilder
            << "Id: " << Configuration::Inst()->Id() << ' '
            << "PID: " << getpid() << ' '
            << "Lock: " << mutex.time << ' ';

    mutex.tick();

    Logger::Inst()->log(MessageBuilder()
            .id(Configuration::Inst()->Id())
            .time(mutex.time)
            .type(Events::Acquire)
            .build());

    mutex.tick();

    stringBuilder << "Unlock: " << mutex.time;

    std::string result;
    std::getline(stringBuilder, result);
    result+='\n';

    int fd = open(Configuration::Inst()->Path().c_str(), O_WRONLY | O_APPEND);
    int stat = flock(fd, LOCK_EX | LOCK_NB);
    if(stat == -1) {
        std::cout << "Flock error" << std::endl;
        throw std::string("Flock error");
    }
    write(fd, result.c_str(), result.size());
    flock(fd, LOCK_UN);
    close(fd);
}