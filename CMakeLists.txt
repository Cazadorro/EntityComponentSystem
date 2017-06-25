cmake_minimum_required(VERSION 3.7)
project(EntityComponentSystem)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp UnitTests.cpp UnitTests.h Entity.cpp Entity.h Component.cpp Component.h PositionComponent.cpp PositionComponent.h HealthComponent.cpp HealthComponent.h)
add_executable(EntityComponentSystem ${SOURCE_FILES})