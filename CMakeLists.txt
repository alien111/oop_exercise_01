cmake_minimum_required(VERSION 3.2)

project(BitString)

add_executable(BitString
	Source.cpp
	BitString.cpp)

set_property(TARGET BitString PROPERTY CXX_STANDART 11)
