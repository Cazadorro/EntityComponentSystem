//
// Created by Shae Bolt on 3/1/2017.
//

#include "PositionComponent.h"

template<>
const ComponentKey ComponentWithKey<InputComponent>::m_key = ONEHOT(0);
template<>
const ComponentKey ComponentWithKey<PositionComponent>::m_key = ONEHOT(1);
template<>
const ComponentKey ComponentWithKey<VelocityComponent>::m_key = ONEHOT(2);
template<>
const ComponentKey ComponentWithKey<NameComponent>::m_key = ONEHOT(3);
template<>
const ComponentKey ComponentWithKey<DisplayCharComponent>::m_key = ONEHOT(4);

PhysicsNode::PhysicsNode(Entity &entity) {
    m_position = static_cast<PositionComponent *>(entity.getComponent(
            PositionComponent::getClassKey()));
    m_velocity = static_cast<VelocityComponent *>(entity.getComponent(
            VelocityComponent::getClassKey()));
}

InputNode::InputNode(Entity &entity) {
    m_input = static_cast<InputComponent *>(entity.getComponent(
            InputComponent::getClassKey()));
    m_velocity = static_cast<VelocityComponent *>(entity.getComponent(
            VelocityComponent::getClassKey()));
}

DisplayNode::DisplayNode(Entity &entity) {
    m_position = static_cast<PositionComponent *>(entity.getComponent(
            PositionComponent::getClassKey()));
    m_displaychar = static_cast<DisplayCharComponent *>(entity.getComponent(
            DisplayCharComponent::getClassKey()));
}