#include <arpa/inet.h>
#include <sys/socket.h>

#include "papa_xmas_conveyor_belt.h"
#include "../gifts/box.h"
#include "../gifts/gift_paper.h"


PapaXmasConveyorBelt::PapaXmasConveyorBelt(const std::string& warp_ip, int warp_port) : wrap(nullptr) {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);

    warp_addr.sin_family = AF_INET;
    warp_addr.sin_port = htons(warp_port);
    inet_aton(warp_ip.c_str(), &warp_addr.sin_addr);

    std::cout << "[CONVEYOR BELT] Waiting Santa at " << warp_ip << ":" << warp_port << std::endl;
}

PapaXmasConveyorBelt::~PapaXmasConveyorBelt() {
    delete wrap;
}

bool PapaXmasConveyorBelt::put(Wrap* object) {
    if (wrap != nullptr) {
        std::cerr << "Conveyor belt already contains a wrap.";
        return false;
    }
    wrap = object;
    return true;
}

Wrap* PapaXmasConveyorBelt::take() {
    auto* result = wrap;
    wrap = nullptr;
    return result;
}

bool PapaXmasConveyorBelt::push_button(ConveyorButton button) {
    switch (button) {
        case IN:
            if (wrap != nullptr) {
                std::cerr << "Conveyor belt already contains a wrap.";
                return false;
            }

            wrap = std::rand() % 2 == 0 ? (Wrap*) new Box() : (Wrap*) new GiftPaper();
            break;
        case OUT:
            // Send to Santa
            if (wrap == nullptr) {
                std::cerr << "Conveyor belt doesn't contain a wrap!";
                return false;
            }

            auto* xmlObject = wrap->to_xml();
            auto data = xmlObject->to_string();
            int sendOk = sendto(sockfd, data.c_str(), data.size() + 1, 0, (sockaddr*) &warp_addr, sizeof(warp_addr));

            std::cout << "[CONVEYOR BELT]: send (" << sendOk << ") " << data << "." << std::endl;
            wrap = nullptr;
            delete xmlObject;
            break;
    }

    return true;
}