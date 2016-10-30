//
// Created by alex on 25.10.16.
//

#include "Sender.h"
#include "Listener.h"
#include "NetManager.h"
#include "Configuration.h"
#include "Node.h"
#include "Packer.h"
#include "MessageBuilder.h"

#include <thread>

#include <netinet/in.h>
#include <strings.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <iostream>

Sender::Sender() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();
    logger = Logger::Inst();
}

Sender::~Sender() {
}

void Sender::sendTo(std::uint32_t id, Message message) {
    auto& nodes = configuration->Nodes();

    int sendfd;
    int port = nodes[id].port;
    std::string address = nodes[id].adress;
    struct sockaddr_in servaddr;

    sendfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    inet_pton(AF_INET, address.c_str(), &servaddr.sin_addr);

    int status;
    do {
        status = connect(sendfd, (struct sockaddr*) &servaddr, sizeof(servaddr));
        if(status == -1) std::this_thread::sleep_for(std::chrono::milliseconds(500));
    } while(status == -1); // we expect, that we don't have problems with network connection therefore we don't set timeout

    char data[Packer::mSize];
    Packer::toBytes(message, data);

    int bytes_sent = 0;
    while(bytes_sent < Packer::mSize) {
        bytes_sent += write(sendfd, data + bytes_sent, Packer::mSize - bytes_sent);
    }

    close(sendfd);
}
