#include "xml_object.h"
#include <sstream>

const size_t kCacheMaxSize = 10;

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

    for (size_t i = 0; i < attributes_count; i++) {
        ss << attribute_names[i] << "=\"" << attribute_values[i] << "\"";
        if (i < attributes_count - 1) ss << " ";
    }

    ss << ">";

    for (size_t i = 0; i < children_count; i++) {
        ss << children[i]->to_string();
    }

    ss << "</" << name << ">";

    return ss.str();
}

std::ostream& operator<<(std::ostream& s, const XMLObject& obj) {
    s << obj.to_string();
    return s;
}

XMLObject* XMLObject::from_string(const std::string& xml) {
    auto* object = new XMLObject();

    int start_close_pos = xml.find('>'),
            end_open_pos = xml.rfind('<');

    int attribute_start = xml.substr(0, start_close_pos).find(' ');

    std::string name;

    if (attribute_start != std::string::npos) {
        name = xml.substr(1, attribute_start - 1);

        std::stringstream buffer;
        auto* attribute_names = new std::string[kCacheMaxSize];
        auto* attribute_values = new std::string[kCacheMaxSize];
        size_t attributes_count = 0;
        short state = 0;
        for (size_t i = attribute_start + 1; i < start_close_pos; i++) {
            if (xml[i] == '=' && state == 0) {
                state = 1;
                attribute_names[attributes_count] = buffer.str();
                buffer.str(std::string());
                i++; // Skip first quote
            } else if ((xml[i] == '\"' || i == start_close_pos - 1) && state == 1) {
                state = 0;
                attribute_values[attributes_count] = buffer.str();
                buffer.str(std::string());
                attributes_count++;
                i++; // Skip space
            } else {
                buffer << xml[i];
            }
        }

        object->attribute_names = new std::string[attributes_count];
        object->attribute_values = new std::string[attributes_count];
        object->attributes_count = attributes_count;

        // Copying
        for (size_t i = 0; i < attributes_count; i++)
        {
            object->attribute_names[i] = attribute_names[i];
            object->attribute_values[i] = attribute_values[i];
        }

        delete[] attribute_names;
        delete[] attribute_values;
    } else name = xml.substr(1, start_close_pos - 1);

    if (start_close_pos != end_open_pos - 1) { // Has children
        int level = 0, start = 0, end = 0;
        bool final = false, close_tag = false;
        auto** children = new XMLObject*[kCacheMaxSize];
        int children_count = 0;

        for (size_t i = start_close_pos + 1; i < end_open_pos; i++) {
            if (xml[i] == '<') {
                if (xml[i + 1] == '/') { // End tag
                    if (--level == 0) { // Close tag of forward child
                        final = true;
                    }
                    close_tag = true;
                } else { // Start tag
                    if (level == 0) {
                        start = i;
                    }
                }
            } else if (xml[i] == '>')
            {
                if (final) {
                    end = i;
                    children[children_count++] = XMLObject::from_string(xml.substr(start, end - start + 1));
                    final = false;
                    close_tag = false;
                } else if (close_tag) {
                    close_tag = false;
                } else level++;
            }
        }

        object->children = new XMLObject*[children_count];
        object->children_count = children_count;

        for (size_t i = 0; i < children_count; i++) {
            object->children[i] = children[i];
        }

        delete[] children;
    }

    object->name = name;

    return object;
}
