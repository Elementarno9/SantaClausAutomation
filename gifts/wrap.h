#pragma once

#include "../objects/object.h"


class Wrap : public Object {
  protected:
    Object* inside;
    bool is_opened = false;
  public:
    Wrap() : inside(nullptr) {}

    virtual bool wrapMeThat(Object* object);

    virtual Object* openMe();

    void closeMe();
};