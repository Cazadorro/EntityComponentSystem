//
// Created by shae on 6/25/17.
//

#include "NamePositionNode.h"

template <>
const uint64_t StaticKeyNode<NamePositionNode>::m_key = NameComponent::classkey() | PositionComponent::classkey();

NamePositionNode::NamePositionNode(Entity &entity)
        : StaticKeyNode(entity) {
    m_name = entity.getComponent<NameComponent>();
    m_position = entity.getComponent<PositionComponent>();
}