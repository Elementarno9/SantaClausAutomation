#pragma once

#include "wrap.h"

class Box : public Wrap {
public:
    bool wrapMeThat(Object* object) override;

    Object* openMe() override;

    void print(std::ostream& s) const override;
};