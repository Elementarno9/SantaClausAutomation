#pragma once

#include "toy.h"

class Teddy : public Toy {
public:
    Teddy(const std::string& name)
            : Toy(name) {
        scream = "gra hu";
    }

    void print(std::ostream& s) const override;
};