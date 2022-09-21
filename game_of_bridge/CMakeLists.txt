cmake_minimum_required(VERSION 3.0.0)
project(bridge VERSION 0.1.0)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

add_executable(
  bridge
  src/main.cpp
)

include_directories(bridge)

target_link_libraries(bridge)