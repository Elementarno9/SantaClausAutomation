#include "gift_paper.h"

void GiftPaper::print(std::ostream& s) const {
    if (inside != nullptr) {
        s << "Gift paper with " << *inside;
    } else {
        s << "Empty gift paper";
    }
}
