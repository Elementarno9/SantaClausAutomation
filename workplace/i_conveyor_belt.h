#pragma once

#include "../gifts/wrap.h"


enum ConveyorButton {
    IN,
    OUT
};

class IConveyorBelt {
  public:
    virtual ~IConveyorBelt() = default;

    virtual bool put(Wrap* object) = 0;

    virtual Wrap* take() = 0;

    virtual bool push_button(ConveyorButton button) = 0;
};