//
// Created by shae on 6/26/17.
//

#include "HealthNameNode.h"

template <>
const uint64_t StaticKeyNode<HealthNameNode>::m_key = HealthComponent::classkey() | NameComponent::classkey();

HealthNameNode::HealthNameNode(Entity &entity)
        : StaticKeyNode(entity) {
    m_health = entity.getComponent<HealthComponent>();
    m_name = entity.getComponent<NameComponent>();
}

