cmake_minimum_required(VERSION 3.19)
project(c++)

set(CMAKE_CXX_STANDARD 17)

add_executable(sorting algorithms/sorting/sort.cpp)
add_executable(ec_test design_patterns/entity_component/main.cpp)
add_executable(generic_observer design_patterns/generic_observer/generic_observer.cpp)