cmake_minimum_required(VERSION 3.4)
project(demo-game)

set(CMAKE_MODULE_PATH "../cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall")

find_library(FIBULA_LIBRARY
             NAMES Fibula
             HINTS "${CMAKE_CURRENT_LIST_DIR}/../libs/include")

include_directories(
        "${CMAKE_CURRENT_LIST_DIR}/../libs/include"
        Core
)

file(GLOB SOURCE_LIST
     *.cpp
     ../src/Core/*.cpp
     )

add_executable(demo-game ${SOURCE_LIST})
target_link_libraries(demo-game Fibula)

add_custom_target(valgrind)