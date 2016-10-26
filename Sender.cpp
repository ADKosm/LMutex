//
// Created by alex on 25.10.16.
//

#include "Sender.h"
#include "Listener.h"
#include "NetManager.h"
#include "Configuration.h"
#include "Node.h"
#include "Packer.h"

#include <thread>

#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>

Sender::Sender() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();
    logger = Logger::Inst();
}

Sender::~Sender() {
}

void Sender::run() {
    for(;;) {
        auto currentMessage = manager->messagesToSend.pop();
        logger->log(currentMessage.second);
        sendTo(currentMessage.first, currentMessage.second);
    }
}

void Sender::sendTo(std::uint32_t id, Message message) {
    auto& nodes = configuration->Nodes();
    Node currentNode = nodes[configuration->Id()];

    int sendfd, connfd;
    int port = currentNode.port;
    std::string address = currentNode.adress;
    struct sockaddr_in servaddr;

    sendfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    int res = inet_pton(AF_INET, address.c_str(), &servaddr.sin_addr);

    int status;
    do {
        status = connect(sendfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
        if(status == -1) std::this_thread::sleep_for(std::chrono::milliseconds(5));
    } while(status == -1); // we expect, that we don't have problems with network connection therefore we don't set timeout

    char data[Packer::mSize];
    Packer::toBytes(message, data);

    int bytes_sent = 0;
    while(bytes_sent < Packer::mSize) {
        send(sendfd, data + bytes_sent, Packer::mSize - bytes_sent, 0);
    }

    shutdown(sendfd, SHUT_RDWR);
    close(sendfd);
}
