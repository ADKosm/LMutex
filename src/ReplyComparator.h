//
// Created by alex on 30.10.16.
//

#ifndef LMUTEX_REPLYCOMPARATOR_H
#define LMUTEX_REPLYCOMPARATOR_H


#include "Message.h"

class replyComparator {
public:
    replyComparator() {}
    ~replyComparator() {}

    bool operator() (const Message& a, const Message& b) const {
        return a.id < b.id;
    }
};

#endif //LMUTEX_REPLYCOMPARATOR_H
