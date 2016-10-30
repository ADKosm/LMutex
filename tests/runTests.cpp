//
// Created by alex on 29.10.16.
//

#include <iostream>
#include <assert.h>

#include "../src/MessageBuilder.h"
#include "../src/LMutex.h"
#include "../src/Logger.h"
#include "TestConfiguration.h"
#include "TestNetManager.h"
#include "TestLogger.h"
#include <vector>

Configuration * Configuration::self = new TestConfiguration();
NetManager * NetManager::self = new TestNetManager();
Logger * Logger::self = new TestLogger();

int controlVariable = 0;

void runner(int id) {
    Configuration * configuration = Configuration::Inst();
    NetManager * netManager = NetManager::Inst();

    configuration->init(id, nullptr);
    netManager->init();

    std::this_thread::sleep_for(std::chrono::milliseconds(700));

    LMutex mutex;
    for(int i = 0; i < 1000; i++) {
        mutex.lock();

        if(i % 100 == 0) std::cout << '.' << std::flush;

        assert(controlVariable == 0);
        controlVariable += 1;

        std::this_thread::sleep_for(std::chrono::milliseconds(5)); // hard work

        assert(controlVariable == 1);
        controlVariable -= 1;

        mutex.unlock();
    }
}

int main() {

    int N = 4;

    std::cout << "Please wait. Testing may takes about " << 5 << " seconds" << std::endl;

    std::vector<std::thread> nodes;
    for(int i = 1; i <= N+1; i++) {
        nodes.push_back(std::thread(runner, i));
    }
    for(auto& thread: nodes) {
        thread.join();
    }
    std::cout << std::endl << "All tests were passed!" << std::endl;
    return 0;
}