cmake_minimum_required(VERSION 3.3)
project(gameZero)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${gameZero_SOURCE_DIR}/cmake")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${gameZero_SOURCE_DIR}/source/headers)

set(SOURCE_FILES main.cpp Game.cpp Game.h)
add_executable(gameZero ${SOURCE_FILES})

target_link_libraries(gameZero ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES})