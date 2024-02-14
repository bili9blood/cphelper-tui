cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(cphelper-tui LANGUAGES C CXX VERSION 0.1.0)

find_package(libhv REQUIRED)
find_package(ftxui REQUIRED)
