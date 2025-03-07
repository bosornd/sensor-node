cmake_minimum_required(VERSION 3.10)

project(sensor-node)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(inc)

file(GLOB SOURCES "src/*.cpp")

add_executable(sensor-node ${SOURCES})
