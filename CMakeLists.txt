cmake_minimum_required(VERSION 3.25)
project(rm2024_t2)

set(CMAKE_CXX_STANDARD 17)

add_executable(data_gen src/data.cpp)
add_executable(checker src/checker.cpp)
add_executable(correct_ans src/T2.cpp)
add_executable(my_ans src/mycode.cpp)
