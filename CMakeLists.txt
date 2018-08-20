project(strratio CXX)
cmake_minimum_required(VERSION 3.9)

add_library(STRRATIO INTERFACE)
target_include_directories(STRRATIO INTERFACE "${PROJECT_SOURCE_DIR}/include/")

add_executable(example example/example.cpp)
set_property(TARGET example PROPERTY CXX_STANDARD 17)
target_link_libraries(example STRRATIO)
