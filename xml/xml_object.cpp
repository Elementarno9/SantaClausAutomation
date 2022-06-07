#include "xml_object.h"
#include <sstream>

XMLObject::~XMLObject() {
    delete[] attribute_names;
    delete[] attribute_values;
    while (children_count-- > 0) delete children[children_count];
    delete[] children;
}

std::string XMLObject::to_string() const {
    std::stringstream ss;

    ss << "<" << name;
    if (attributes_count > 0) ss << " ";

    for (size_t i = 0; i < attributes_count; i++)
    {
        ss << attribute_names[i] << "=\"" << attribute_values[i] << "\"";
        if (i < attributes_count - 1) ss << " ";
    }

    ss << ">";

    for (size_t i = 0; i < children_count; i++)
    {
        ss << children[i]->to_string();
    }

    ss << "</" << name << ">";

    return ss.str();
}

std::ostream& operator<<(std::ostream& s, const XMLObject& obj) {
    s << obj.to_string();
    return s;
}
