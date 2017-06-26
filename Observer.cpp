//
// Created by shae on 6/25/17.
//

#include "Observer.h"

SameEntityChecker::SameEntityChecker(const Entity &entity) : m_entity(&entity) {

}

bool SameEntityChecker::operator()(const Node &node) const {
    return m_entity == node.entity();
}
