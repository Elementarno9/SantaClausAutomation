#include <iostream>
#include "wrap.h"


bool Wrap::wrapMeThat(Object* object) {
    if (inside != nullptr) {
        std::cerr << "Cannot wrap because it already contains object." << std::endl;
        return false;
    }
    inside = object;
    return true;
}

Object* Wrap::openMe() {
    Object* result = inside;
    inside = nullptr;
    return result;
}

void Wrap::closeMe() {
    is_opened = true;
}