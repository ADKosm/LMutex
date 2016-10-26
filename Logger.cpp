//
// Created by alex on 26.10.16.
//

#include "Logger.h"
#include "Configuration.h"
#include "LMutex.h"
#include <string>
#include <fstream>
#include <sys/types.h>
#include <unistd.h>
#include <chrono>
#include <ctime>

Logger::Logger() {
    configuration = Configuration::Inst();
}

Logger::~Logger() {
}


void Logger::log(Message message) {
    std::string path = configuration->Path() + std::to_string(configuration->Id()) + std::string(".log");

    std::time_t realTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

    std::ofstream logFile(path, std::ofstream::app);
    logFile << getpid()
            << message.id
            << message.type
            << message.time
            << ctime(&realTime);
    logFile.close();
}
