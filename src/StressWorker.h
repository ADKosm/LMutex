//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_STRESSWORKER_H
#define LMUTEX_STRESSWORKER_H

#include "Worker.h"
class LMutex;

class StressWorker : public Worker {

public:
    StressWorker();
    ~StressWorker();

    virtual void run() override;

private:
    int number;
};


#endif //LMUTEX_STRESSWORKER_H
