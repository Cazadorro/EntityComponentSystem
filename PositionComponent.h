//
// Created by Shae Bolt on 3/1/2017.
//

#ifndef UNTITLED_POSITIONCOMPONENT_H
#define UNTITLED_POSITIONCOMPONENT_H

#include "Component.h"
#include "ComponentNode.h"
#include <string>
#include <vector>
#include "Entity.h"
#include <iostream>

constexpr uint64_t bit(const uint64_t n) {
    return static_cast<uint64_t>(1) << (n);
}

class InputComponent : public ComponentWithKey<InputComponent> {
public:
    std::string *m_input_ptr;
    InputComponent(std::string *input_ptr) : m_input_ptr(input_ptr) {};
private:
};


class PositionComponent :public ComponentWithKey<PositionComponent> {
public:
    int64_t m_x;
    int64_t m_y;
    int64_t m_z;
    PositionComponent(const int64_t x, const int64_t y, const int64_t z) :
            m_x(x), m_y(y), m_z(z) {std::cout << "hello"<< std::endl;};
private:
};


class VelocityComponent :public ComponentWithKey<VelocityComponent> {
public:
    double m_velocity;
    VelocityComponent(const double velocity) : m_velocity(velocity) {};
private:
};


class NameComponent :public ComponentWithKey<NameComponent>  {
public:
    std::string m_name;
    NameComponent(const std::string name) :
            m_name(name) {};
private:
};


class PhysicsNode : public ComponentNode {
public:
    PositionComponent *m_position;
    VelocityComponent *m_velocity;
    PhysicsNode(Entity& entity);
    static uint64_t getKey(){
        return PositionComponent::getClassKey() | VelocityComponent::getClassKey();
    }
private:
};

class InputNode : public ComponentNode {
public:
    InputComponent *m_input;
    VelocityComponent *m_velocity;
    InputNode(Entity& entity);
    static uint64_t getKey(){
        return InputComponent::getClassKey() | VelocityComponent::getClassKey();
    }
private:
};


#endif //UNTITLED_POSITIONCOMPONENT_H
