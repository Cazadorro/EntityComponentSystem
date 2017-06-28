//
// Created by shae on 6/27/17.
//

#include "NameNode.h"

template<>
const uint64_t StaticKeyNode<NameNode>::m_key = NameComponent::classkey();

NameNode::NameNode(Entity &entity) : StaticKeyNode(entity) {
    m_name_component = entity.getComponent<NameComponent>();
}

std::string NameNode::getName() const {
    return m_name_component->m_name;
}
