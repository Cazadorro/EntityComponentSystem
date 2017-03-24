//
// Created by Shae Bolt on 3/1/2017.
//

#include "PositionComponent.h"

template <>
const uint64_t ComponentWithKey<InputComponent>::m_key = bit(1);
template <>
const uint64_t ComponentWithKey<PositionComponent>::m_key = bit(2);
template <>
const uint64_t ComponentWithKey<VelocityComponent>::m_key = bit(3);
template <>
const uint64_t ComponentWithKey<NameComponent>::m_key = bit(4);
template <>
const uint64_t ComponentWithKey<DisplayCharComponent>::m_key = bit(5);

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