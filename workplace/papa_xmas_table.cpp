#include "papa_xmas_table.h"


Object* PapaXmasTable::take(int id) {
    if (count == 0 || id < -1 || id >= count) {
        std::cerr << "Invalid id for an object on table!";
        return nullptr;
    }

    if (id == -1) id = count - 1;

    Object* result = container[id];
    for (int i = id; i < count; i++) {
        container[i] = container[i + 1];
    }
    count--;
    return result;
}

bool PapaXmasTable::put(Object* object) {
    if (count >= max_count) {
        std::cerr << "Table is full! Collapsing.";
        return false;
    }
    container[count++] = object;
    return true;
}

PapaXmasTable::PapaXmasTable(int max_count)
        : count(0), max_count(max_count), container(new Object* [max_count + 1]) {

}

PapaXmasTable::~PapaXmasTable() {
    while (count-- > 0) {
        delete container[count];
    }
    delete[] container;
}

std::string* PapaXmasTable::look() {
    auto* result = new std::string[count + 1];
    for (int i = 0; i < count; i++) {
        result[i] = container[i]->get_name();
    }
    return result;
}
