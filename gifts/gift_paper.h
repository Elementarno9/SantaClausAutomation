#pragma once

#include "wrap.h"

class GiftPaper : public Wrap {
public:
    void print(std::ostream& s) const override;
};