//
// Created by alex on 30.10.16.
//

#include <iostream>
#include <string>

#include "../src/NetManager.h"
#include "../tests/TestLogger.h"
#include "../src/Configuration.h"
#include "../src/LMutex.h"
#include "../src/MessageBuilder.h"

Configuration * Configuration::self = nullptr;
NetManager * NetManager::self = nullptr;
Logger * Logger::self = new TestLogger();

LMutex mutex;

void lock(std::uint32_t id) {
    Message lockMessage = MessageBuilder()
            .id(0)
            .time(0)
            .type(Events::UserLock)
            .build();

    NetManager::Inst()->sendTo(id, lockMessage, &mutex);
}

void unlock(std::uint32_t id) {
    Message unlockMessage = MessageBuilder()
            .id(0)
            .time(0)
            .type(Events::UserUnlock)
            .build();

    NetManager::Inst()->sendTo(id, unlockMessage, &mutex);
}

void kill() {
    Message killMessage = MessageBuilder()
            .id(0)
            .time(0)
            .type(Events::UserKill)
            .build();

    NetManager::Inst()->sendToAll(killMessage, &mutex);
}

void print() {
    std::cout << "Your nodes: " << std::endl;
    for(auto& n : Configuration::Inst()->Nodes()) {
        std::cout << n.first << ' ';
    }
    std::cout << std::endl;
    std::cout << "Available commands: " << std::endl;
    std::cout << "> lock [id] -- take mutex on node [id]" << std::endl
        << "> unlock [id] -- release mutex on node [id]" << std::endl
        << "> kill -- terminate all nodes" << std::endl;
}

int main(int argc, char ** argv) {
    Configuration * configuration = Configuration::Inst();
    configuration->init(argc, argv);

    NetManager * manager = NetManager::Inst();
    manager->init();

    std::string task;
    for(;;) {
        print();
        std::cout << ">> ";
        std::cin >> task;
        if(task == "lock") {
            int id;
            std::cin >> id;
            lock(static_cast<std::uint32_t>(id));
        } else if(task == "unlock") {
            int id;
            std::cin >> id;
            unlock(static_cast<std::uint32_t >(id));
        } else if(task == "kill") {
            kill();
            break;
        } else {
            std::cout << "Incorrect command" << std::endl;
        }
    }

    std::cout << "If you run cli from launcher.py, press Ctrl+C to close programm" << std::endl;

    return 0;
}