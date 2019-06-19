cmake_minimum_required(VERSION 3.14)
project(essentials)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O0")

# equivalent to ' '.join(line.split()) for each line in python
add_executable(cleanup src/cleanup.cc src/cat.cc)

add_executable(cat src/cat.cc)