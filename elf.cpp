#include "persons/papa_xmas_elf.h"
#include "workplace/conveyor_belt_rand.h"
#include "workplace/table_rand.h"

int main(int argc, char *argv[])
{
    std::string ip = IP_DEFAULT;
    int port = PORT_DEFAULT;
    if (argc >= 3 && std::string(argv[1]) == "-w") {
        ip = argv[2];
    }

    if (argc >= 5 && std::string(argv[3]) == "-p") {
        port = std::stoi(argv[4]);
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