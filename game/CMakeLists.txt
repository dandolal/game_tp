cmake_minimum_required(VERSION 3.10)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game main.cpp Army.h wariors.h game.h wariors.cpp Army.cpp game.cpp)
