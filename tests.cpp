#include "objects/teddy.h"
#include "objects/little_pony.h"
#include "gifts/box.h"
#include "gifts/gift_paper.h"
#include "persons/elf.h"

Object** MyUnitTests()
{
    Object** toys = new Object*[2];
    toys[0] = new LittlePony("Happy Pony");
    toys[1] = new Teddy("Cuddles");

    std::cout << "Two objects were created: " << *toys[0] << " and " << *toys[1] << "." << std::endl;

    ((Toy*)toys[0])->isTaken();
    ((Toy*)toys[1])->isTaken();

    return toys;
}

Object* MyUnitTests(Object** objects)
{
    Elf elf("Tobby");

    elf.take((Wrap*)objects[1]);
    elf.wrap_object(objects[0]); // Fails
    elf.open_wrap();
    elf.wrap_object(objects[0]);
    elf.put();
    elf.take((Wrap*)objects[2]);
    elf.wrap_object(objects[1]);

    return elf.put();
}

int main()
{
    // 1st unit test
    auto toys = MyUnitTests();

    delete toys[0];
    delete toys[1];
    delete[] toys;

    // 2nd unit test
    auto gift = MyUnitTests(new Object*[] { new Teddy("Cuddles"), new Box(), new GiftPaper()});

    auto box = ((Wrap*)gift)->openMe();
    auto inside = ((Wrap*)box)->openMe();

    delete inside;
    delete box;
    delete gift;

    return 0;
}