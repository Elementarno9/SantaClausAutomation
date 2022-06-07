#pragma once

#include "../objects/object.h"
#include "../xml/xml_object.h"

class SantaClaus
{
private:
    Object* deserialize(XMLObject* xmlObject);
public:
    void handle_gift(const std::string& xml_filepath);
};