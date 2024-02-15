cmake_minimum_required(VERSION 3.21)

option(USE_STATIC_LIBHV "Use static libhv" OFF)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

if(${USE_STATIC_LIBHV})
  set(LIBHV_LIB hv_static)
else()
  set(LIBHV_LIB hv)
endif()

project(cphelper-tui LANGUAGES C CXX VERSION 0.1.0)

find_package(libhv REQUIRED)
find_package(ftxui REQUIRED)

file(
  GLOB_RECURSE CPHELPER_TUI_SOURCES
  ${CMAKE_CURRENT_LIST_DIR}/src/*.cc ${CMAKE_CURRENT_LIST_DIR}/src/*.h
)

add_executable(cphelper-tui ${CPHELPER_TUI_SOURCES})

target_include_directories(cphelper-tui PRIVATE ${CMAKE_CURRENT_LIST_DIR}/include)
target_link_libraries(cphelper-tui PRIVATE ${LIBHV_LIB} ftxui::screen ftxui::dom ftxui::component)
