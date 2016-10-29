//
// Created by alex on 25.10.16.
//

#define LISTENQ 1024
#define SA struct sockaddr

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
#include <iostream>

Listener::Listener() {
    manager = NetManager::Inst();
    configuration = Configuration::Inst();
}

Listener::~Listener() {
}

void Listener::run() {
    auto& nodes = configuration->Nodes();
    Node current = nodes[configuration->Id()];

    int listenfd, connfd;
    int port = current.port;
    struct sockaddr_in servaddr, ip_name;
    socklen_t len = sizeof(ip_name);

    listenfd = socket(AF_INET, SOCK_STREAM, 0);

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);

    bind(listenfd, (SA *) &servaddr, sizeof(servaddr));

    listen(listenfd, LISTENQ);

    for(;;) {
//        std::this_thread::sleep_for(std::chrono::seconds(10)); // TODO: remove this line
        connfd = accept(listenfd, (SA*)&ip_name, &len);

        std::cout << "Receiving some message" << std::endl;

        char rawData[Packer::mSize];

        int read_bytes = 0;
        while( read_bytes < Packer::mSize ) {
           read_bytes += read(connfd, rawData + read_bytes, Packer::mSize - read_bytes);
        }

        Message readMessage = Packer::toMessage(rawData);

        std::cout << "This message from " << readMessage.id << ": " << readMessage.time << ' ' << int(readMessage.type) << std::endl;

        manager->NetEvents()->push(readMessage);

//        shutdown(connfd, SHUT_RDWR);
        close(connfd);
    }
}

