#include "warp_machine.h"
#include <sys/socket.h>
#include <cstring>
#include <arpa/inet.h>
#include <iostream>


const size_t kBufferSize = 256;

WarpMachine::WarpMachine(std::string ip, int port) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    const int optval = 1;
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval));

    bzero(&addr, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (sockaddr*) &addr, sizeof(addr));

    inet_aton(ip.c_str(), &(mreq.imr_multiaddr));
    mreq.imr_interface.s_addr = htonl(INADDR_ANY);

    setsockopt(sockfd, IPPROTO_IP, IP_ADD_MEMBERSHIP, &mreq, sizeof(mreq));

    std::cout << "[WARP MACHINE] Listen to " << ip << ":" << port << "..." << std::endl;
}

std::string WarpMachine::receive() const {
    char buffer[kBufferSize];
    recv(sockfd, buffer, kBufferSize, 0);

    return buffer;
}
