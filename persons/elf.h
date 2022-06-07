#pragma once

#include <string>
#include "../gifts/wrap.h"
#include "../workplace/i_table.h"
#include "../workplace/i_conveyor_belt.h"

class Elf {
private:
    std::string name;
    Wrap* wrap = nullptr;
public:
    Elf(std::string name) : name(name) {}

    void say(const std::string& text) const;

    bool take(Wrap* object);

    bool take(ITable* table);

    bool take(IConveyorBelt* belt);

    Wrap* put();

    bool send(IConveyorBelt* belt);

    Object* open_wrap() const;

    bool wrap_object(Object* object) const;
};