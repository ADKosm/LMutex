//
// Created by alex on 25.10.16.
//

#ifndef LMUTEX_CONFIGURATION_H
#define LMUTEX_CONFIGURATION_H

#include <cstdint>
#include <map>
#include "Node.h"

#include "Worker.h"

class Configuration {
public:
    static Configuration * Inst() {
        if(!self) self = new Configuration();
        return self;
    }

    void init(int argv, char ** argc);

    std::uint32_t Id();
    std::map<uint32_t, Node> & Nodes();
    std::string Type();
    std::string Path();

    Worker * getWorker();

private:
    Configuration();
    ~Configuration();

    static Configuration * self;

    std::uint32_t id;
    std::map< std::uint32_t , Node> nodes;
    std::string type;
    std::string path;
};

Configuration * Configuration::self = nullptr;
#endif //LMUTEX_CONFIGURATION_H
