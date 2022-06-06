#pragma once

#include "object.h"

class Toy : public Object {
protected:
    std::string scream;
public:
    Toy(std::string name)
            : Object(name) {}

    virtual void isTaken();
};
