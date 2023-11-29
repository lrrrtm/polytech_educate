cmake_minimum_required(VERSION 3.25)
project(educate)

set(CMAKE_CXX_STANDARD 17)

add_executable(educate main.cpp lrclass.h lrclass.cpp lrclassSat.h lrclassSat.cpp vector.h vector.cpp)
