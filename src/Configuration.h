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
        if(self == nullptr) self = new Configuration();
        return self;
    }

    virtual void init(int argv, char ** argc);

    virtual std::uint32_t Id();
    virtual std::map<uint32_t, Node> & Nodes();
    virtual std::string Type();
    virtual std::string Path();
    virtual std::string LogDir();

    virtual Worker * getWorker();

    virtual ~Configuration();

    bool isUserLock();
    void setUserLock(bool value);

    bool isUserUnlock();
    void setUserUnlock(bool value);

protected:
    Configuration();

    static Configuration * self;

    std::uint32_t id;
    std::map< std::uint32_t , Node> nodes;
    std::string type;
    std::string path;
    std::string logDir;

    bool userLock;
    bool userUnlock;
};

//Configuration * Configuration::self = nullptr;
#endif //LMUTEX_CONFIGURATION_H
