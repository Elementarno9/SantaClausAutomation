#pragma once

#include "../objects/object.h"
#include "../xml/xml_object.h"
#include "../workplace/warp_machine.h"


class SantaClaus
{
private:
    Object* deserialize(XMLObject* xmlObject);
public:
    void handle_gift(const std::string& xml);
    void handle_gift_from_file(const std::string& xml_filepath);

    [[noreturn]] void work(WarpMachine* warp_machine);

    void say(const std::string& text) const;
};