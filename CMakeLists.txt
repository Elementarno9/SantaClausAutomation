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

        persons/elf.cpp
        )

add_executable(tests tests.cpp ${CPP_FILES})