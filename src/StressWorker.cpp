//
// Created by alex on 25.10.16.
//

#include "StressWorker.h"
#include "LMutex.h"
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
        number(5)
{}

StressWorker::~StressWorker() {
}

void StressWorker::run() {
    std::cout << "Begin running" << std::endl;
    LMutex mutex;
    std::cout << "Create Mutex" << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    for(int i = 0; i < number; i++) {
        mutex.lock();
        writeToFile(mutex);
        mutex.unlock();
    }
    mutex.finish();
}


void StressWorker::writeToFile(LMutex &mutex) {
    std::stringstream stringBuilder;
    stringBuilder
            << "Id: " << Configuration::Inst()->Id() << ' '
            << "PID: " << getpid() << ' '
            << "Lock: " << mutex.time << ' ';

    mutex.tick();

    stringBuilder << "Unlock: " << mutex.time;

    std::string result;
    std::getline(stringBuilder, result);
    result+='\n';

    std::cout << result << std::endl;

    int fd = open(Configuration::Inst()->Path().c_str(), O_WRONLY | O_APPEND);
    int stat = flock(fd, LOCK_EX | LOCK_NB);
    if(stat == -1) throw std::string("Flock error");
    write(fd, result.c_str(), result.size());
    flock(fd, LOCK_UN);
    close(fd);
}