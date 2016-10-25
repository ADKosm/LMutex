//
// Created by alex on 25.10.16.
//

#include "Configuration.h"
#include "UserWorker.h"
#include "StressWorker.h"

// [type of work] [path to file] [number of nodes] [current id] { [id] [address] [port] [id] [address] [port] ... }
void Configuration::init(int argv, char **argc) {
    int numberOfNodes = std::stoi(std::string(argc[3]));
    int currentId = std::stoi(std::string(argc[4]));
    std::string currentType = std::string(argc[1]);
    std::string pathToFile = std::string(argc[2]);

    id = static_cast<std::uint32_t >(currentId);
    type = currentType;
    path = pathToFile;

    for(int i = 0; i < numberOfNodes; i++) {
        int curr = i*3 + 4;
        Node n;
        n.id = static_cast<std::uint32_t >(std::stoi(std::string(argc[curr])));
        n.adress = std::string(argc[curr+1]);
        n.port = static_cast<std::uint32_t >(std::stoi(std::string(argc[curr+2])));
        nodes[n.id] = n;
    }
    //TODO: throw exception when incorrect arguments
}

std::uint32_t Configuration::Id() {
    return id;
}

std::map<uint32_t, Node> & Configuration::Nodes() {
    return nodes;
}

std::string Configuration::Type() {
    return type;
}

std::string Configuration::Path() {
    return path;
}

Configuration::Configuration() {
}

Configuration::~Configuration() {
}


Worker *Configuration::getWorker() {
    if(type == "user") {
        return new UserWorker();
    } else if(type == "stress") {
        return new StressWorker();
    }
    // TODO: throw exception when incorrect argument
}

