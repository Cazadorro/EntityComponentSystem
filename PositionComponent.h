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



class InputComponent : public ComponentWithKey<InputComponent> {
public:
    std::string *m_input_ptr;

    InputComponent(std::string *input_ptr) : m_input_ptr(input_ptr) {};
private:
};


class PositionComponent : public ComponentWithKey<PositionComponent> {
public:
    int64_t m_x;
    int64_t m_y;
    int64_t m_z;

    PositionComponent(const int64_t x, const int64_t y, const int64_t z) :
            m_x(x), m_y(y), m_z(z) { std::cout << "hello" << std::endl; };
private:
};


class VelocityComponent : public ComponentWithKey<VelocityComponent> {
public:
    double m_magnitude;
    double m_x;
    double m_y;
    double m_z;


    VelocityComponent(const double magnitude, const double x, const double
    y, const double z) : m_magnitude(magnitude), m_x(x), m_y(y), m_z(z){};
private:
};


class NameComponent : public ComponentWithKey<NameComponent> {
public:
    std::string m_name;

    NameComponent(const std::string name) :
            m_name(name) {};
private:
};

class DisplayCharComponent : public ComponentWithKey<DisplayCharComponent> {
public:
    std::string m_displaychar;

    DisplayCharComponent(const std::string displaychar) :
            m_displaychar(displaychar) {};
private:
};


class PhysicsNode : public ComponentNode {
public:
    PositionComponent *m_position;
    VelocityComponent *m_velocity;

    PhysicsNode(Entity &entity);

    static ComponentKey getKey() {
        return PositionComponent::getClassKey() |
               VelocityComponent::getClassKey();
    }

private:
};

class InputNode : public ComponentNode {
public:
    InputComponent *m_input;
    VelocityComponent *m_velocity;

    InputNode(Entity &entity);

    static ComponentKey getKey() {
        return InputComponent::getClassKey() | VelocityComponent::getClassKey();
    }

private:
};

class DisplayNode : public ComponentNode {
public:
    PositionComponent *m_position;
    DisplayCharComponent *m_displaychar;

    DisplayNode(Entity &entity);

    static ComponentKey getKey() {
        return PositionComponent::getClassKey() |
               DisplayCharComponent::getClassKey();
    }

private:
};

#endif //UNTITLED_POSITIONCOMPONENT_H
