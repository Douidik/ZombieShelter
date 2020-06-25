cmake_minimum_required(VERSION 3.16)
project(shelter)
set(CMAKE_CXX_STANDARD 20)

#project sources
file(GLOB_RECURSE src src/*.cpp)
file(GLOB_RECURSE hdr src/*.h)
include_directories(src/)

#dependencies
find_package(sdl2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRECTORIES})

add_executable(shelter ${src} ${hdr})

target_link_libraries(shelter ${SDL2_LIBRARIES})