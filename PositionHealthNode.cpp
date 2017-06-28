//
// Created by shae on 6/25/17.
//

#include "PositionHealthNode.h"

template<>
const uint64_t StaticKeyNode<PositionHealthNode>::m_key = PositionComponent::classkey() | HealthComponent::classkey();

PositionHealthNode::PositionHealthNode(Entity &entity)
        : StaticKeyNode(entity){
    m_position_component = entity.getComponent<PositionComponent>();
    m_health_component = entity.getComponent<HealthComponent>();
}
