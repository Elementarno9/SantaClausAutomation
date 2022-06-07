#include <fstream>
#include <sstream>

#include "santa_claus.h"
#include "../objects/teddy.h"
#include "../objects/little_pony.h"
#include "../gifts/box.h"
#include "../gifts/gift_paper.h"

Object* SantaClaus::deserialize(XMLObject* xmlObject) {
    bool is_wrap = false;
    Object* obj;
    if (xmlObject->name == "Box") {
        obj = new Box();
        is_wrap = true;
    } else if (xmlObject->name == "GiftPaper") {
        obj = new GiftPaper();
        is_wrap = true;
    } else if (xmlObject->name == "Teddy") {
        obj = new Teddy(xmlObject->get_attribute("name"));
    } else if (xmlObject->name == "LittlePony") {
        obj = new LittlePony(xmlObject->get_attribute("name"));
    } else {
        say("Whaaaat is it?!?!?");
        return nullptr;
    }

    if (is_wrap && xmlObject->children_count == 1) {
        Wrap* wrap = (Wrap*)obj;
        wrap->openMe();
        wrap->wrapMeThat(deserialize(xmlObject->children[0]));
        wrap->closeMe();
    }

    return obj;
}

void SantaClaus::handle_gift(const std::string& xml_filepath) {
    std::ifstream file(xml_filepath);
    if (!file) {
        say("Something is wrong...");
        return;
    }

    std::stringstream ss;
    ss << file.rdbuf();

    auto xmlObject = XMLObject::from_string(ss.str());
    Wrap* gift = (Wrap*)deserialize(xmlObject);

    say("Quality controle!");
    Object* toy = gift->openMe();
    say("Ho ho ho! There is " + toy->get_name() + " inside " + gift->get_name());
    gift->wrapMeThat(toy);
    gift->closeMe();
}

void SantaClaus::say(const std::string& text) const {
    std::cout << "Santa says `" << text << "`." << std::endl;
}
