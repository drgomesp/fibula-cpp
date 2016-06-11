cmake_minimum_required(VERSION 3.5)
project(Fibula)

message(STATUS "Fibula: v2.0.0")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework OpenGl -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system -lGLEW -std=c++14 -Wall -pedantic")

set(FIBULA_INCLUDE_DIR "include")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_LIST_DIR})

include_directories(${FIBULA_INCLUDE_DIR})

# This stuff needed to put every include file into needed directory when we do make install
file(GLOB BRIDGE ${FIBULA_INCLUDE_DIR}/Fibula/Bridge/*.hpp)
file(GLOB CORE ${FIBULA_INCLUDE_DIR}/Fibula/Core/*.hpp)
file(GLOB EVENTS ${FIBULA_INCLUDE_DIR}/Fibula/Events/*.hpp)
file(GLOB GRAPHICS ${FIBULA_INCLUDE_DIR}/Fibula/Graphics/*.hpp)
file(GLOB GRAPHICS_TILEMAP ${FIBULA_INCLUDE_DIR}/Fibula/Graphics/TileMap/*.hpp)
file(GLOB_RECURSE SOURCE_LIST src/*.cpp)

set(HEADER_LIST
    ${BRIDGE}
    ${CORE}
    ${EVENTS}
    ${GRAPHICS}
    ${GRAPHICS_TILEMAP}
    )

# GLM
find_package(GLM REQUIRED)
if (NOT GLM_FOUND)
    message(SEND_ERROR "Failed to find GLM")
    return()
else ()
    include_directories(${GLM_INCLUDE_DIRS})
endif ()

# GLEW
find_package(GLEW REQUIRED)
if (NOT GLEW_FOUND)
    message(SEND_ERROR "Failed to find GLEW")
    return()
else ()
    include_directories(${GLEW_INCLUDE_DIRS})
endif ()

# SFML
find_package(SFML 2.2 REQUIRED)
if (NOT SFML_FOUND)
    message(SEND_ERROR "Failed to find SFML 2")
    return()
else ()
    include_directories(${SFML_INCLUDE_DIRS})
endif ()

add_library(Fibula SHARED ${SOURCE_LIST} ${HEADER_LIST})

target_link_libraries(Fibula
                      ${GLM_LIBRARIES}
                      ${GLEW_LIBRARIES}
                      ${SFML_LIBARIES}
                      )

# When we do 'make install' it will put .so file into lib directory and include files into include directory
install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION ${PROJECT_NAME})
install(FILES ${BRIDGE} DESTINATION include/${PROJECT_NAME}/Bridge/)
install(FILES ${CORE} DESTINATION include/${PROJECT_NAME}/Core/)
install(FILES ${EVENTS} DESTINATION include/${PROJECT_NAME}/Events/)
install(FILES ${GRAPHICS} DESTINATION include/${PROJECT_NAME}/Graphics/)
install(FILES ${GRAPHICS_TILEMAP} DESTINATION include/${PROJECT_NAME}/Graphics/TileMap/)

add_custom_target(install_${PROJECT_NAME}
                  make install
                  DEPENDS ${PROJECT_NAME}
                  COMMENT "Installing ${PROJECT_NAME}")
