#pragma once

#include "../objects/object.h"


class ITable {
  public:
    virtual Object* take(int id) = 0;

    virtual ~ITable() = default;

    virtual bool put(Object* object) = 0;

    virtual std::string* look() = 0;
};