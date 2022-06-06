#include "little_pony.h"

void LittlePony::print(std::ostream& s) const {
    s << "Little pony named `" << name << "`";
}