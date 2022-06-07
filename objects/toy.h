#pragma once

#include "object.h"


class Toy : public Object {
  protected:
    std::string scream;
  public:
    Toy(const std::string& name)
            : Object(name) {}

    void isTaken() const;
};
