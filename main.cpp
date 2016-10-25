#include <iostream>
#include "NetManager.h"
#include "Worker.h"
#include "Configuration.h"

/*
 * using:
 * node [type of work] [path to file] [number of nodes] [current id] { [id] [address] [port] [id] [address] [port] ... }
 * [type of work] is in { 'stress', 'user' }
 * */

int main(int argc, char **argv) {

    Configuration * configuration = Configuration::Inst();
    configuration->init(argc, argv);

    NetManager * manager = NetManager::Inst();
    manager->init();
    manager->run();

    Worker * worker = configuration->getWorker();
    worker->run();

    delete manager;
    delete worker;
    delete configuration;

    return 0;
}