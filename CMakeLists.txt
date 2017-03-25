cmake_minimum_required(VERSION 3.6)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Entity.cpp Entity.h Component.cpp Component.h Observer.cpp Observer.h ComponentNode.cpp ComponentNode.h System.cpp System.h PositionComponent.cpp PositionComponent.h ComponentKey.cpp ComponentKey.h)
add_executable(untitled ${SOURCE_FILES})