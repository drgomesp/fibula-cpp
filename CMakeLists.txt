cmake_minimum_required(VERSION 3.5)
project(Fibula)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -W -pedantic")

set(SOURCE_FILES main.cpp EventDispatcher/Event.cpp EventDispatcher/Event.h EventDispatcher/Listener.cpp EventDispatcher/Listener.h EventDispatcher/Dispatcher.cpp EventDispatcher/Dispatcher.h EventDispatcher/Payload.h)
add_executable(Fibula ${SOURCE_FILES})