#include "elf.h"

void Elf::say(const std::string& text) const {
    std::cout << "Elf " << name << " says `" << text << "`." << std::endl;
}

bool Elf::take(Wrap* object) {
    if (wrap != nullptr) {
        std::cerr << "Must clear hands before take a wrap.";
        say("Ooops!");
        return false;
    }
    say("whistles while working");
    wrap = object;
    return true;
}

Wrap* Elf::put() {
    Wrap* result = wrap;
    wrap = nullptr;
    return result;
}

Object* Elf::open_wrap() const {
    if (wrap == nullptr) {
        std::cerr << "There is no wrap!";
        say("Ooops!");
        return nullptr;
    }
    return wrap->openMe();
}

bool Elf::wrap_object(Object* object) const {
    if (!wrap->wrapMeThat(object)) {
        say("Ooooops!");
        return false;
    }
    wrap->closeMe();

    say("tuuuut tuuut tuut!");
    std::cout << "Result: " << *wrap << std::endl;
    return true;
}
