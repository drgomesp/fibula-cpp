cmake_minimum_required(VERSION 3.4)
project(Fibula)

include_directories(BEFORE src/)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lSDL2_image -std=c++14 -Wall -W -pedantic")

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
    src/Fibula/Graphics/Window/WindowAdapter.hpp
    src/Fibula/Graphics/Window/Adapter/SDLWindowAdapter.cpp
    src/Fibula/Graphics/Window/Adapter/SDLWindowAdapter.hpp
    src/Fibula/Graphics/TileMap/Tile.cpp
    src/Fibula/Graphics/TileMap/Tile.hpp
    src/Fibula/Graphics/TileMap/TileSet.cpp
    src/Fibula/Graphics/TileMap/TileSet.hpp
    src/Fibula/Graphics/TileMap/TileMapLayer.cpp
    src/Fibula/Graphics/TileMap/TileMapLayer.hpp
    src/Fibula/Graphics/TileMap/TileMap.cpp
    src/Fibula/Graphics/TileMap/TileMap.hpp

    src/demo-game/Listeners/SDL/MousePositionListener.cpp
    src/demo-game/Listeners/SDL/MousePositionListener.hpp
    src/demo-game/Core/Kernel.cpp
    src/demo-game/Core/Kernel.cpp src/demo-game/Core/Kernel.hpp

    src/Fibula/Graphics/Window/RendererAdapter.hpp
    src/Fibula/Graphics/Window/Adapter/SDLRendererAdapter.cpp src/Fibula/Graphics/Window/Adapter/SDLRendererAdapter.hpp src/Fibula/Graphics/TileMap/RendererAdapter.hpp src/Fibula/Graphics/TileMap/RendererAdapter.cpp src/Fibula/Graphics/TileMap/RendererAdapter.hpp src/Fibula/Graphics/TileMap/Renderer/OrthogonalRenderer.cpp src/Fibula/Graphics/TileMap/Renderer/OrthogonalRenderer.hpp src/Fibula/Graphics/Window/Adapter/SFMLWindowAdapter.cpp src/Fibula/Graphics/Window/Adapter/SFMLWindowAdapter.hpp src/Fibula/Graphics/Window/Adapter/SFMLRendererAdapter.cpp src/Fibula/Graphics/Window/Adapter/SFMLRendererAdapter.hpp)

add_executable(Fibula ${SOURCE_FILES})
#
#get_cmake_property(_variableNames VARIABLES)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

include_directories(${GLEW_INCLUDE_DIRS})
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(Fibula ${SDL2_LIBRARIES})
target_link_libraries(Fibula ${SFML_LIBRARIES})
target_link_libraries(Fibula ${GLEW_LIBRARIES})

add_custom_target(valgrind)
