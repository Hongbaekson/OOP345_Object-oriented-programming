cmake_minimum_required(VERSION 3.10)
project(home)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(home
        345_w2_at_home_prof.cpp
        reflect.txt
        Text.cpp
        Text.h
        Timekeeper.cpp
        Timekeeper.h
        utils.o
        w2
        w2.cpp)
