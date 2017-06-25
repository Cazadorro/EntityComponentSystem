//
// Created by shae on 6/25/17.
//

#include "Entity.h"
#include <algorithm>
#include <cassert>

SameComponentChecker::SameComponentChecker(Component *component) {
    m_key = component->key();
}

bool SameComponentChecker::operator()(Component *component) {
    return m_key == component->key();
}

void Entity::addComponent(Component *component) {
    if (hasComponentKey(component)) {
        removeComponent(component);
    }
    m_components.push_back(component);
    m_key |= component->key();
}

std::uint64_t Entity::key() {
    return m_key;
}

std::size_t Entity::numberOfComponents() {
    return m_components.size();
}

bool Entity::hasKey(std::uint64_t key) {
    return (m_key & key) != 0;
}

void Entity::removeComponent(Component *component) {
    SameComponentChecker isSameComponent(component);
    auto erase_itr = std::find_if(m_components.begin(), m_components.end(), isSameComponent);
    assert(erase_itr != m_components.end());
    m_components.erase(std::find_if(m_components.begin(), m_components.end(), isSameComponent));
}

bool Entity::hasComponentKey(Component *component) {
    return hasKey(component->key());
}


