//
// Created by alex on 30.10.16.
//

#ifndef LMUTEX_TESTCONFIGURATION_H
#define LMUTEX_TESTCONFIGURATION_H

#include "../src/Configuration.h"
#include <map>
#include <thread>
#include <mutex>

class TestConfiguration : public Configuration {

public:
    virtual void init(int argv, char **argc) override;

    virtual std::uint32_t Id() override;

    virtual std::map<uint32_t, Node> &Nodes() override;

    virtual std::string Type() override;

    virtual std::string Path() override;

    virtual std::string LogDir() override;

    virtual Worker *getWorker() override;

    virtual ~TestConfiguration() override;

private:
    std::map<std::thread::id, uint32_t > ids;
    std::mutex mutex;
};


#endif //LMUTEX_TESTCONFIGURATION_H
