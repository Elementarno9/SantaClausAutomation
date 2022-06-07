cmake_minimum_required(VERSION 3.17)
project(SantaClausAutomation)

set(CMAKE_CXX_STANDARD 20)

SET(CPP_FILES

        objects/object.cpp
        objects/toy.cpp
        objects/little_pony.cpp
        objects/teddy.cpp

        gifts/wrap.cpp
        gifts/box.cpp
        gifts/gift_paper.cpp

        persons/i_elf.cpp
        persons/papa_xmas_elf.cpp
        persons/santa_claus.cpp

        workplace/i_table.cpp
        workplace/i_conveyor_belt.cpp
        workplace/papa_xmas_table.cpp
        workplace/papa_xmas_conveyor_belt.cpp
        workplace/table_rand.cpp
        workplace/conveyor_belt_rand.cpp

        xml/xml_object.cpp
        )

add_executable(tests tests.cpp ${CPP_FILES})
add_executable(santa santa.cpp ${CPP_FILES})