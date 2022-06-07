#include "little_pony.h"

void LittlePony::print(std::ostream& s) const {
    s << "Little pony named `" << name << "`";
}

XMLObject* LittlePony::to_xml() const {
    return new XMLObject("LittlePony",
                         new std::string[]{"name"},
                         new std::string[]{name},
                         1);
}
