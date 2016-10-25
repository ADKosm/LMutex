//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_NODE_H
#define LMUTEX_NODE_H

#include <cstdint>
#include <string>

struct Node {
    std::uint32_t id;
    int port;
    std::string adress;
};


#endif //LMUTEX_NODE_H
