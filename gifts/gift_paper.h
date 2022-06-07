#pragma once

#include "wrap.h"


class GiftPaper : public Wrap {
  public:
    GiftPaper() { name = "Gift paper"; }

    void print(std::ostream& s) const override;

    XMLObject* to_xml() const override;
};