cmake_minimum_required(VERSION 3.3)
project(cpp_stuff
        )
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

SET(CHRONO_SRC chrono.cpp)
add_executable(chrone ${CHRONO_SRC})