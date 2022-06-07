#pragma once

#include <iostream>
#include <string>

#include "../xml/xml_object.h"


class Object {
  protected:
    std::string name;
  public:
    explicit Object(const std::string& name = "")
            : name(name) {}

    virtual ~Object() = default;

    const std::string& get_name() const;

    virtual void print(std::ostream& s) const = 0;

    virtual XMLObject* to_xml() const = 0;

    friend std::ostream& operator<<(std::ostream& s, const Object& obj);
};