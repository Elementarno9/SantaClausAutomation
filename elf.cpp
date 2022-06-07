#include "persons/papa_xmas_elf.h"
#include "workplace/conveyor_belt_rand.h"
#include "workplace/table_rand.h"


int main(int argc, char* argv[]) {
    std::string ip = IP_DEFAULT;
    int port = PORT_DEFAULT;

    for (int i = 1; i < argc; i++) {
        auto arg = std::string(argv[i]);
        if (argc > i + 1) {
            if (arg == "-w") {
                ip = argv[i + 1];
            } else if (arg == "-p") {
                port = std::stoi(argv[i + 1]);
            }
            i++;
        }
    }

    IElf* elf = new PapaXmasElf("Bobby");

    ITable* table = new TableRand(10);
    IConveyorBelt* belt = new ConveyorBeltRand(ip, port);

    elf->work(table, belt);

    delete elf;
    delete table;
    delete belt;

    return 0;
}