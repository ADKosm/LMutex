//
// Created by alex on 26.10.16.
//

#ifndef LMUTEX_LOGGER_H
#define LMUTEX_LOGGER_H

#include <string>
#include "Configuration.h"
#include "LMutex.h"
#include "Message.h"

class Logger {
public:
    static Logger * Inst() {
        if(!self) self = new Logger();
        return self;
    }

    void log(Message message);

    ~Logger();
private:
    Logger();

    static Logger * self;

    Configuration * configuration;
};

#endif //LMUTEX_LOGGER_H
