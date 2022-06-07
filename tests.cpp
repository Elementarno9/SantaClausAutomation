#include "objects/teddy.h"
#include "objects/little_pony.h"
#include "gifts/box.h"
#include "gifts/gift_paper.h"
#include "persons/papa_xmas_elf.h"
#include "workplace/table_rand.h"
#include "workplace/conveyor_belt_rand.h"

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
    PapaXmasElf elf("Tobby");

    elf.take((Wrap*)objects[1]);
    elf.wrap_object(objects[0]); // Fails
    elf.open_wrap();
    elf.wrap_object(objects[0]);
    elf.put();
    elf.take((Wrap*)objects[2]);
    elf.wrap_object(objects[1]);

    return elf.put();
}

void NextUnitTest(ITable* table, IConveyorBelt* belt)
{
    PapaXmasElf elf("Bob");

    elf.work(table, belt);

    delete table;
    delete belt;
}

ITable* createTable()
{
    auto* table = new TableRand(10);

    return table;
}

IConveyorBelt* createConveyorBelt()
{
    auto* belt = new ConveyorBeltRand();

    return belt;
}

void print_test(int i) {
    std::cout << std::endl << "========= test #" << i << " =========" << std::endl;
}

int main()
{
    // 1st unit test
    print_test(1);
    auto toys = MyUnitTests();

    delete toys[0];
    delete toys[1];
    delete[] toys;

    // 2nd unit test
    print_test(2);
    auto gift = MyUnitTests(new Object*[3] { new Teddy("Cuddles"), new Box(), new GiftPaper()});

    auto box = ((Wrap*)gift)->openMe();
    auto inside = ((Wrap*)box)->openMe();

    delete inside;
    delete box;
    delete gift;

    // 3rd unit test
    print_test(3);
    NextUnitTest(createTable(), createConveyorBelt());

    return 0;
}