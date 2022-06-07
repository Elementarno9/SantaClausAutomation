#include "persons/santa_claus.h"
#include "workplace/warp_machine.h"
#include "workplace/constants.h"


int main(int argc, char* argv[]) {
    SantaClaus santa;

    std::string ip = IP_DEFAULT;
    int port = PORT_DEFAULT;

    for (int i = 1; i < argc; i++) {
        auto arg = std::string(argv[i]);
        if (argc > i + 1) {
            if (arg == "-w") {
                ip = argv[i + 1];
            } else if (arg == "-p") {
                port = std::stoi(argv[i + 1]);
            }
            i++;
        } else {
            santa.handle_gift_from_file(arg);
        }
    }

    WarpMachine warp(ip, port);
    santa.work(&warp);

    return 0;
}