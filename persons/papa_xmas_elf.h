#pragma once

#include "i_elf.h"

class PapaXmasElf : public IElf {
public:
    explicit PapaXmasElf(const std::string& name) : IElf(name) {}

    void say(const std::string& text) const override;

    bool take(Wrap* object) override;

    bool take(ITable* table) override;

    bool take(IConveyorBelt* belt) override;

    Wrap* put() override;

    bool send(IConveyorBelt* belt) override;

    Object* open_wrap() const override;

    bool wrap_object(Object* object) const override;

    void work(ITable* table, IConveyorBelt* belt) override;
};