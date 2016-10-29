//
// Created by alex on 29.10.16.
//

#include <iostream>
#include "../src/MessageBuilder.h"
#include "../src/LMutex.h"
#include "../src/Logger.h"

Configuration * Configuration::self = nullptr;
NetManager * NetManager::self = nullptr;
Logger * Logger::self = nullptr;

int main() {
    std::priority_queue<Message, std::vector<Message>, qComparator > q;
    q.push(MessageBuilder().time(1).id(1).type(0).build());
    q.push(MessageBuilder().time(1).id(2).type(0).build());

    while(!q.empty()) {
        Message a = q.top();
        q.pop();
        std::cout << a.id << ' ' << a.time << std::endl;
    }

    std::queue<Message> s;
    s.push(MessageBuilder().time(4).id(5).type(6).build());
    s.push(MessageBuilder().time(1).id(2).type(3).build());

    while(!s.empty()) {
        Message a = s.front();
        s.pop();
        std::cout << a.id << ' ' << a.time << std::endl;
    }
    return 0;
}