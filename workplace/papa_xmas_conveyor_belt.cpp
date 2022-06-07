#include "papa_xmas_conveyor_belt.h"
#include "../gifts/box.h"
#include "../gifts/gift_paper.h"

PapaXmasConveyorBelt::PapaXmasConveyorBelt() : wrap(nullptr) {}

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
            std::cout << "[CONVEYOR BELT]: send " << *wrap->to_xml() << "." << std::endl;
            wrap = nullptr;
            break;
    }

    return true;
}