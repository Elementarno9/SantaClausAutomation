#include "object.h"

std::ostream& operator<<(std::ostream& s, const Object& obj) {
    obj.print(s);
    return s;
}
