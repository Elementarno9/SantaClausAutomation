#include <iostream>
#include <arpa/inet.h>
#include "persons/santa_claus.h"
#include "workplace/warp_machine.h"
#include "workplace/constants.h"

int main(int argc, char *argv[])
{
    SantaClaus santa;

    std::string ip = IP_DEFAULT;
    int port = PORT_DEFAULT;
    if (argc >= 3 && std::string(argv[1]) == "-w") {
        ip = argv[2];
    }

    if (argc >= 5 && std::string(argv[3]) == "-p") {
        port = std::stoi(argv[4]);
    }

    WarpMachine warp(ip, port);
    santa.work(&warp);

    return 0;
}