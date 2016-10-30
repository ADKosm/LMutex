//
// Created by alex on 30.10.16.
//

#include "TestConfiguration.h"

void TestConfiguration::init(int argv, char **argc) {
    std::unique_lock<std::mutex> lock(mutex);
    ids[std::this_thread::get_id()] = static_cast<uint32_t >(argv);

    Node n;
    n.id = static_cast<uint32_t >(argv);
    n.adress = std::string("");
    n.port = 0;

    nodes[n.id] = n;
}

std::uint32_t TestConfiguration::Id() {
    return ids[std::this_thread::get_id()];
}

std::map<uint32_t, Node> &TestConfiguration::Nodes() {
    return Configuration::Nodes();
}

std::string TestConfiguration::Type() {
    return Configuration::Type();
}

std::string TestConfiguration::Path() {
    return Configuration::Path();
}

std::string TestConfiguration::LogDir() {
    return Configuration::LogDir();
}

Worker *TestConfiguration::getWorker() {
    return Configuration::getWorker();
}

TestConfiguration::~TestConfiguration() {

}

