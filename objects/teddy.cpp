#include "teddy.h"

void Teddy::print(std::ostream& s) const {
    s << "Teddy named `" << name << "`";
}

XMLObject* Teddy::to_xml() const {
    return new XMLObject("Teddy",
                         new std::string[]{"name"},
                         new std::string[]{name},
                         1);
}
