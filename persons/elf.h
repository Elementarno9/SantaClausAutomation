#pragma once

#include <string>
#include "../gifts/wrap.h"

class Elf {
private:
    std::string name;
    Wrap* wrap = nullptr;
public:
    Elf(std::string name) : name(name) {}

    void say(const std::string& text) const;

    bool take(Wrap* object);

    Wrap* put();

    Object* open_wrap() const;

    bool wrap_object(Object* object) const;
};