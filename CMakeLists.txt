cmake_minimum_required(VERSION 3.7)
project(EntityComponentSystem)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp UnitTests.cpp UnitTests.h Entity.cpp Entity.h Component.cpp Component.h PositionComponent.cpp PositionComponent.h HealthComponent.cpp HealthComponent.h Observer.cpp Observer.h Node.cpp Node.h PositionHealthNode.cpp PositionHealthNode.h key.cpp key.h testingutility.h NameComponent.cpp NameComponent.h NamePositionNode.cpp NamePositionNode.h HealthNameNode.cpp HealthNameNode.h Game.cpp Game.h)
add_executable(EntityComponentSystem ${SOURCE_FILES})