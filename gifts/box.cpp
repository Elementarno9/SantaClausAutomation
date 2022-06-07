#include "box.h"

bool Box::wrapMeThat(Object* object) {
    if (!is_opened) {
        std::cerr << "Box have to be opened before wrapping." << std::endl;
        return false;
    }
    return Wrap::wrapMeThat(object);
}

Object* Box::openMe() {
    is_opened = true;
    return Wrap::openMe();
}

void Box::print(std::ostream& s) const {
    if (inside != nullptr) {
        s << "Box with " << *inside;
    } else {
        s << "Empty box";
    }
}

XMLObject* Box::to_xml() const {
    return new XMLObject("Box",
                         nullptr, nullptr, 0,
                         inside != nullptr ? new XMLObject* []{inside->to_xml()} : nullptr,
                         inside != nullptr ? 1 : 0);
}
