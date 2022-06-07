#include "table_rand.h"
#include "../objects/teddy.h"
#include "../objects/little_pony.h"

TableRand::TableRand(int max_count) : PapaXmasTable(max_count) {
    for (int i = 0; i < max_count; i++) {
        Object* obj;

        switch (std::rand() % 4) {
            case 0:
                obj = new Teddy("Cuddles");
                break;
            case 1:
                obj = new LittlePony("Unicorn");
                break;
            case 2:
                obj = new Teddy("Polar bear");
                break;
            case 3:
                obj = new LittlePony("Funny");
                break;
        }

        container[i] = obj;
    }
    count = max_count;
}
