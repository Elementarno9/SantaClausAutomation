#pragma once

#include "toy.h"

class LittlePony : public Toy {
public:
    LittlePony(const std::string& name)
            : Toy(name) {
        scream = "yo man";
    }

    void print(std::ostream& s) const override;
};