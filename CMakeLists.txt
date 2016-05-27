cmake_minimum_required(VERSION 3.4)
project(Fibula)

include_directories(BEFORE src/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall -W -pedantic")

# Boost 1.60.0
find_package(boost 1.60.0 REQUIRED smart_ptr container)

# GLM
find_package(GLM REQUIRED)
string(STRIP ${GLM_INCLUDE_DIRS} GLM_INCLUDE_DIRS)

# GLEW
find_package(GLEW REQUIRED)
string(STRIP ${GLEW_INCLUDE_DIRS} GLEW_INCLUDE_DIRS)
string(STRIP ${GLEW_LIBRARIES} GLEW_LIBRARIES)

# SDL 2
find_package(SDL2 REQUIRED)
string(STRIP ${SDL2_INCLUDE_DIRS} SDL2_INCLUDE_DIRS)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

# SFML 2.3
find_package(SFML 2.2 COMPONENTS system window graphics network audio REQUIRED)

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
    src/Fibula/Graphics/Adapter/SDLWindowAdapter.hpp)

add_executable(Fibula ${SOURCE_FILES})

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${GLM_INCLUDE_DIRS})
include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(Fibula ${SDL2_LIBRARIES})
target_link_libraries(Fibula ${SFML_LIBRARIES})
target_link_libraries(Fibula ${GLEW_LIBRARIES})

add_custom_target(valgrind)
