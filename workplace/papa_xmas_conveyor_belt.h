#pragma once

#include "i_conveyor_belt.h"
#include "../gifts/wrap.h"

class PapaXmasConveyorBelt : public IConveyorBelt {
private:
    Wrap* wrap;
public:
    PapaXmasConveyorBelt();

    ~PapaXmasConveyorBelt() override;

    bool put(Wrap* object) override;

    Wrap* take() override;

    bool push_button(ConveyorButton button) override;
};