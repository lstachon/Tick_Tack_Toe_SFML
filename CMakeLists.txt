cmake_minimum_required(VERSION 3.19)
project(KolkoKrzyzykProjekt)

set(CMAKE_CXX_STANDARD 17)

set(SFML_INCLUDE_DIR "./Users/lukasz/SFML-2.5.1/include")
set(SFML_LIBRARY_DIR "./Users/lukasz/SFML-2.5.1/build/lib")

link_directories(SFML_LIBRARY_DIR)
include_directories(SFML_INCLUDE_DIR)

file(COPY "textures" DESTINATION ${CMAKE_BINARY_DIR})

find_package(SFML 2.5.1 COMPONENTS system window graphics network)

file(GLOB source_files "src/*.cpp")

add_executable("${PROJECT_NAME}" ${source_files})
target_link_libraries ("${PROJECT_NAME}" sfml-graphics sfml-window sfml-system)

