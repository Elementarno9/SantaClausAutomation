#include <iostream>
#include "persons/santa_claus.h"

int main(int argc, char *argv[])
{
    SantaClaus santa;

    for (size_t i = 0; i < argc - 1; i++)
    {
        santa.handle_gift(argv[i + 1]);
    }

    return 0;
}