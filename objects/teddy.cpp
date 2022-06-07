#include "teddy.h"


void Teddy::print(std::ostream& s) const {
    s << "Teddy named `" << name << "`";
}

XMLObject* Teddy::to_xml() const {
    return new XMLObject("Teddy",
                         new std::string[1]{"name"},
                         new std::string[1]{name},
                         1);
}
