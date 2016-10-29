//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_SAFEQUEUE_H
#define LMUTEX_SAFEQUEUE_H

#include <queue>
#include <mutex>
#include <condition_variable>

template <class T>
class SafeQueue {
public:
    SafeQueue() {}

    ~SafeQueue() {}

    void push(const T &message) {
        std::unique_lock<std::mutex> ulock(mutex);
        queue.push(message);
        ulock.unlock();
        cond.notify_one();
    }

    T pop() {
        std::unique_lock<std::mutex> ulock(mutex);
        while(queue.empty()){
            cond.wait(ulock) ;
        }
        T item = queue.front();
        queue.pop();
        return item;
    }

private:
    std::queue<T> queue;
    std::mutex mutex;
    std::condition_variable cond;
};


#endif //LMUTEX_SAFEQUEUE_H
