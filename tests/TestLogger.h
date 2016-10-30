//
// Created by alex on 30.10.16.
//

#ifndef LMUTEX_TESTLOGGER_H
#define LMUTEX_TESTLOGGER_H

#include "../src/Logger.h"

class TestLogger : public Logger {

public:
    TestLogger();
    virtual ~TestLogger() override;

    virtual void log(Message message) override;
};


#endif //LMUTEX_TESTLOGGER_H
