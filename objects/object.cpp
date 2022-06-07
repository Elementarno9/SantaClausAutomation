#include "object.h"


std::ostream& operator<<(std::ostream& s, const Object& obj) {
    obj.print(s);
    return s;
}

const std::string& Object::get_name() const {
    return name;
}
