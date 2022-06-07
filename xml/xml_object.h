#pragma once

#include <string>

class XMLObject {
public:
    std::string name;
    std::string* attribute_names;
    std::string* attribute_values;
    XMLObject** children;
    size_t attributes_count = 0;
    size_t children_count = 0;

    explicit XMLObject(const std::string& name = "",
                       std::string* attribute_names = nullptr,
                       std::string* attribute_values = nullptr,
                       size_t attributes_count = 0,
                       XMLObject** children = nullptr,
                       size_t children_count = 0)
            : name(name), attribute_names(attribute_names), attribute_values(attribute_values), children(children),
              attributes_count(attributes_count), children_count(children_count) {}

    ~XMLObject();

    static XMLObject* from_string(const std::string& xml);
    std::string to_string() const;
    friend std::ostream& operator<<(std::ostream& s, const XMLObject& obj);
};