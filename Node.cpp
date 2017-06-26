//
// Created by shae on 6/25/17.
//

#include "Node.h"

Node::Node(Entity &entity) : m_entity(&entity) {

}

const Entity *Node::entity() const {
    return m_entity;
}
