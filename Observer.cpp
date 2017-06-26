//
// Created by shae on 6/25/17.
//

#include "Observer.h"

SameNodeChecker::SameNodeChecker(const Entity &entity) : m_entity(&entity) {

}

bool SameNodeChecker::operator()(const Node &node) const {
    return m_entity == node.entity();
}
