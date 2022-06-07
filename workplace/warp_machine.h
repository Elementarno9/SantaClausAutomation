#pragma once

#include <netinet/in.h>
#include <string>


class WarpMachine {
  private:
    int sockfd;
    sockaddr_in addr;
    ip_mreq mreq;
  public:
    WarpMachine(std::string ip, int port);

    std::string receive() const;
};