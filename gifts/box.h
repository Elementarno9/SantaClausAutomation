#pragma once

#include "wrap.h"

class Box : public Wrap {
public:
    Box() { name = "Box"; }

    bool wrapMeThat(Object* object) override;

    Object* openMe() override;

    void print(std::ostream& s) const override;

    XMLObject* to_xml() const override;
};