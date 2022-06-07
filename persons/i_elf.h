#pragma once

#include <string>
#include "../gifts/wrap.h"
#include "../workplace/i_table.h"
#include "../workplace/i_conveyor_belt.h"

class IElf
{
protected:
    std::string name;
    Wrap* wrap = nullptr;
public:
    explicit IElf(const std::string& name) : name(name) {};
    virtual ~IElf() {
        delete wrap;
    }

    virtual void say(const std::string& text) const = 0;

    virtual bool take(Wrap* object) = 0;

    virtual bool take(ITable* table) = 0;

    virtual bool take(IConveyorBelt* belt) = 0;

    virtual Wrap* put() = 0;

    virtual bool send(IConveyorBelt* belt) = 0;

    virtual Object* open_wrap() const = 0;

    virtual bool wrap_object(Object* object) const = 0;

    virtual void work(ITable* table, IConveyorBelt* belt) = 0;
};