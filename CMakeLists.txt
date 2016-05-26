cmake_minimum_required(VERSION 3.5)
project(Fibula)

include_directories(BEFORE src/)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -W -pedantic")

find_package(SDL2 REQUIRED)

set(SOURCE_FILES
    main.cpp
    src/Fibula/Core/Kernel.cpp
    src/Fibula/Core/Kernel.h
    src/Fibula/Core/KernelAwareListener.h
    src/Fibula/Core.h
    src/Fibula/EventDispatcher/Event.h
    src/Fibula/EventDispatcher/Listener.h
    src/Fibula/EventDispatcher/Dispatcher.cpp
    src/Fibula/EventDispatcher/Dispatcher.h
    src/Fibula/EventDispatcher/Payload.h
    src/Fibula/EventDispatcher.h
    src/Fibula/Graphics/Window.cpp
    src/Fibula/Graphics/Window.h
    src/Fibula/Graphics.h
    src/Fibula/Bridge/EventDispatcher/SDLEventListener.cpp
    src/Fibula/Bridge/EventDispatcher/SDLEventListener.h
    src/Fibula/Bridge/EventDispatcher/SDLEvent.h)

add_executable(Fibula ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS})
target_link_libraries(Fibula ${SDL2_LIBRARIES})

add_custom_target(valgrind)