#include "objects/teddy.h"
#include "objects/little_pony.h"

Object** MyUnitTests()
{
    Object** toys = new Object*[2];
    toys[0] = new LittlePony("Happy Pony");
    toys[1] = new Teddy("Cuddles");

    std::cout << "Two objects were created: " << *toys[0] << " and " << *toys[1] << std::endl;

    ((Toy*)toys[0])->isTaken();
    ((Toy*)toys[1])->isTaken();

    return toys;
}

int main()
{
    auto toys = MyUnitTests();

    delete toys[0];
    delete toys[1];
    delete[] toys;
    return 0;
}