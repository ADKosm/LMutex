//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_WORKER_H
#define LMUTEX_WORKER_H

class LMutex;

class Worker {
public:
    Worker() {}
    virtual ~Worker() {}

    virtual void run() = 0;

    void writeToFile(LMutex &mutex);
};


#endif //LMUTEX_WORKER_H
