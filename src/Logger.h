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
        if(self == nullptr) self = new Logger();
        return self;
    }

    virtual void log(Message message);

    virtual ~Logger();

protected:
    Logger();

    static Logger * self;

    Configuration * configuration;
};

#endif //LMUTEX_LOGGER_H
