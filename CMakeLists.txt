cmake_minimum_required(VERSION 3.4)
project(Fibula)

include_directories(BEFORE src/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -W -pedantic")

# SDL 2
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_INCLUDE_DIRS} SDL2_INCLUDE_DIRS)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

set(SOURCE_FILES
        main.cpp
        src/Fibula/Core/Kernel.cpp
        src/Fibula/Core/Kernel.hpp
        src/Fibula/Core/KernelAwareListener.hpp
        src/Fibula/EventDispatcher/Event.hpp
        src/Fibula/EventDispatcher/ListenerInterface.hpp
        src/Fibula/EventDispatcher/Dispatcher.cpp
        src/Fibula/EventDispatcher/Dispatcher.hpp
        src/Fibula/EventDispatcher/Payload.hpp
        src/Fibula/Bridge/EventDispatcher/SDLEventListener.cpp
        src/Fibula/Bridge/EventDispatcher/SDLEventListener.hpp
        src/Fibula/Bridge/EventDispatcher/SDLEvent.hpp
        src/Fibula/Bridge/EventDispatcher/SDLPayload.hpp
        src/Fibula/EventDispatcher/Payload.hpp
        src/Fibula/Console/ConsoleListener.cpp
        src/Fibula/Console/ConsoleListener.hpp
        src/Fibula/Console/ConsoleEvent.hpp
        src/Fibula/Graphics/WindowAdapterInterface.hpp
        src/Fibula/Graphics/Adapter/SDLWindowAdapter.cpp
        src/Fibula/Graphics/Adapter/SDLWindowAdapter.hpp
        src/demo-game/Listeners/SDL/MousePositionListener.cpp
        src/demo-game/Listeners/SDL/MousePositionListener.hpp
        src/demo-game/Core/Kernel.cpp
        src/demo-game/Core/Kernel.cpp src/demo-game/Core/Kernel.hpp
        )

add_executable(Fibula ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIRS})

target_link_libraries(Fibula ${SDL2_LIBRARIES})

add_custom_target(valgrind)
