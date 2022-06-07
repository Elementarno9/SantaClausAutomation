#pragma once

#include "papa_xmas_conveyor_belt.h"


class ConveyorBeltRand : public PapaXmasConveyorBelt {
  public:
    explicit ConveyorBeltRand(const std::string& warp_ip = IP_DEFAULT, int warp_port = PORT_DEFAULT)
            : PapaXmasConveyorBelt(warp_ip, warp_port) {}

};