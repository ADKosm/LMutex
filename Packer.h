//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_PACKER_H
#define LMUTEX_PACKER_H

#include "Message.h"

class Packer {
public:
    static int mSize;

    static void toBytes(Message m, char * bytes) {
        union {
            Message message;
            char data[mSize];
        } u;

        u.message = m;

        for(int i = 0; i < mSize; i++) bytes[i] = u.data[i];
    }

    static Message toMessage(char * bytes) {
        union {
            Message message;
            char data[mSize];
        } u;

        for(int i = 0; i < mSize; i++) u.data[i] = bytes[i];

        return u.message;
    }
};

int Packer::mSize = sizeof(Message);

#endif //LMUTEX_PACKER_H
