cmake_minimum_required(VERSION 3.20)
project(EDR-Agent VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    src/main.cpp
    src/Linux/Logger.cpp
    src/Linux/ProcessHelper.cpp
)

include_directories(include)
include_directories(include/Linux)

add_executable(EDR-Agent ${SOURCES})

message(STATUS ">> Linux EDR Agent is ready to run!")
