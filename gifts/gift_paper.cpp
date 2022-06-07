#include "gift_paper.h"


void GiftPaper::print(std::ostream& s) const {
    if (inside != nullptr) {
        s << "Gift paper with " << *inside;
    } else {
        s << "Empty gift paper";
    }
}

XMLObject* GiftPaper::to_xml() const {
    return new XMLObject("GiftPaper",
                         nullptr, nullptr, 0,
                         inside != nullptr ? new XMLObject* [1]{inside->to_xml()} : nullptr,
                         inside != nullptr ? 1 : 0);
}
