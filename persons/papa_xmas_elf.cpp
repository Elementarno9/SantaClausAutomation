#include "papa_xmas_elf.h"

void PapaXmasElf::say(const std::string& text) const {
    std::cout << "Elf " << name << " says `" << text << "`." << std::endl;
}

bool PapaXmasElf::take(Wrap* object) {
    if (wrap != nullptr) {
        std::cerr << "Must clear hands before take a wrap.";
        say("Ooops!");
        return false;
    }
    say("whistles while working");
    wrap = object;
    return true;
}

Wrap* PapaXmasElf::put() {
    Wrap* result = wrap;
    wrap = nullptr;
    return result;
}

Object* PapaXmasElf::open_wrap() const {
    if (wrap == nullptr) {
        std::cerr << "There is no wrap!";
        say("Ooops!");
        return nullptr;
    }
    return wrap->openMe();
}

bool PapaXmasElf::wrap_object(Object* object) const {
    if (!wrap->wrapMeThat(object)) {
        say("Ooooops!");
        return false;
    }
    wrap->closeMe();

    say("tuuuut tuuut tuut!");
    std::cout << "Result: " << *wrap << std::endl;
    return true;
}

bool PapaXmasElf::take(ITable* table) {
    if (wrap == nullptr) {
        say("I ne'd a wr'ap!");
        return false;
    }

    auto overview = table->look();
    int count = 0;
    while (!overview[count].empty()) count++;

    if (count == 0) {
        say("Em'ty tabl'!");
        return false;
    }

    wrap->openMe();
    wrap_object(table->take(std::rand() % count));
    wrap->closeMe();

    return true;
}

bool PapaXmasElf::take(IConveyorBelt* belt) {
    if (wrap != nullptr) {
        say("I have a wr'ap!");
        return false;
    }

    wrap = belt->take();
    if (wrap == nullptr) {
        say("puuuuuuush!");
        belt->push_button(IN);
        wrap = belt->take();
    }
    return true;
}

bool PapaXmasElf::send(IConveyorBelt* belt) {
    if (wrap == nullptr) {
        say("I ne'd a wr'ap!");
        return false;
    }

    auto* gift = put();
    if (!belt->put(gift)) {
        say("Oi oi oi!");
        take(gift);
        return false;
    }

    belt->push_button(OUT);
    say("yaaaaaa!");
    return true;
}

void PapaXmasElf::work(ITable* table, IConveyorBelt* belt) {
    say("Sta't wo'kin!");

    take(belt);
    while (take(table))
    {
        send(belt);
        take(belt);
    }

    say("Goo s'eeeep");
}
