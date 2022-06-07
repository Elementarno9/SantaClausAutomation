#include "toy.h"

void Toy::isTaken() const {
    std::cout << "The " << *this << " screams `" << scream << "`!" << std::endl;
}
