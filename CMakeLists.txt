cmake_minimum_required(VERSION 3.9)
#require modern c++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Games_Engineering)

#### Setup Directories ####
#Main output directory
SET(OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/")
#output all dll from all libs into main build folder
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIRECTORY})

#### add external dependencies ####
add_subdirectory("lib/sfml")
set(SFML_INCS "lib/sfml/include")
link_directories("${CMAKE_BINARY_DIR}/lib/sfml")

#### adds TDRacer folder #####
file(GLOB_RECURSE SOURCES TDRacer/*.cpp TDRacer/*.h)
add_executable(TDRacer ${SOURCES})
target_include_directories(TDRacer PRIVATE ${SFML_INCS})
target_link_libraries(TDRacer ecm sfml-graphics)

#### adds B2D - Box2D phyics library
add_subdirectory("lib/b2d/Box2D")
include_directories("lib/b2d/Box2D/")
set(B2D_INCS "lib/b2d/Box2D/")
link_directories("{CMAKE_BINARY_DIR}/lib/sfml/lib")

##physics
file (GLOB_RECURSE SOURCES Box2D/*.cpp Box2D/*.h)
target_include_directories(TDRacer SYSTEM PRIVATE ${SFML_INCS} ${B2D_INCS})
target_link_libraries(TDRacer Box2D)
set(EXECUTABLES ${EXECUTABLES} TDRacer)

####Tile loader lib #########
file (GLOB_RECURSE SOURCE_FILES ecm/*.cpp ecm/*.h)
add_library(ecm STATIC ${SOURCE_FILES})
target_include_directories(ecm INTERFACE "${CMAKE_SOURCE_DIR}/ecm/" SYSTEM PRIVATE ${SFML_INCS})
target_link_libraries(ecm PRIVATE sfml-graphics)