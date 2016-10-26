#include <iostream>
#include "NetManager.h"
#include "Worker.h"
#include "Configuration.h"
#include "Logger.h"

/*
 * using:
 * node [type of work] [path to file] [log directory] [number of nodes] [current id] { [id] [address] [port] [id] [address] [port] ... }
 * [type of work] is in { 'stress', 'user' }
 * end of log directory must be '/'
 * */

Configuration * Configuration::self = nullptr;
NetManager * NetManager::self = nullptr;
Logger * Logger::self = nullptr;

int main(int argc, char **argv) {

    Configuration * configuration = Configuration::Inst();
    configuration->init(argc, argv);

    Logger * logger = Logger::Inst();

    NetManager * manager = NetManager::Inst();
    manager->init();
    manager->run();

    Worker * worker = configuration->getWorker();
    worker->run();

    delete manager;
    delete worker;
    delete configuration;
    delete logger;

    return 0;
}