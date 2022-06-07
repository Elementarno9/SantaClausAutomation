#pragma once

#include <netinet/in.h>

#include "i_conveyor_belt.h"
#include "../gifts/wrap.h"
#include "constants.h"

class PapaXmasConveyorBelt : public IConveyorBelt {
private:
    Wrap* wrap;
    int sockfd;
    sockaddr_in warp_addr;
public:
    explicit PapaXmasConveyorBelt(const std::string& warp_ip = IP_DEFAULT, int warp_port = PORT_DEFAULT);

    ~PapaXmasConveyorBelt() override;

    bool put(Wrap* object) override;

    Wrap* take() override;

    bool push_button(ConveyorButton button) override;
};