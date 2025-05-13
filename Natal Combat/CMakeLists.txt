cmake_minimum_required(VERSION 3.30.5)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled src/main.cpp
        src/Armor.cpp
        src/Attack.cpp
        src/Attribute.cpp
        src/Character.cpp
        src/Weapon.cpp
        src/Hero.cpp)
