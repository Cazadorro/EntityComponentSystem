//
// Created by shae on 6/25/17.
//

#include "Entity.h"
#include <algorithm>
#include <cassert>

SameComponentChecker::SameComponentChecker(Component *component) : m_key(component->key()) {
}

bool SameComponentChecker::operator()(Component *component) const {
    return m_key == component->key();
}

SameComponentChecker::SameComponentChecker(std::uint64_t key) : m_key(key) {
}

void Entity::addComponent(Component *component) {
    if (hasComponentKey(component)) {
        removeComponent(component);
    }
    m_components.push_back(component);
    m_key |= component->key();
}

std::uint64_t Entity::key() const {
    return m_key;
}

std::size_t Entity::numberOfComponents() const {
    return m_components.size();
}

bool Entity::hasKey(const uint64_t key) const {
    return (m_key & key) != 0;
}

void Entity::removeComponent(Component *component) {
    auto erase_itr = getComponentIterator(component);
    assert(erase_itr != m_components.end());
    m_components.erase(erase_itr);
}

bool Entity::hasComponentKey(Component *component) const {
    return hasKey(component->key());
}

std::vector<Component *>::iterator Entity::getComponentIterator(Component *component) {
    SameComponentChecker isSameComponent(component);
    return std::find_if(m_components.begin(), m_components.end(), isSameComponent);
}

std::vector<Component *>::iterator Entity::getComponentIterator(std::uint64_t key) {
    SameComponentChecker isSameComponent(key);
    return std::find_if(m_components.begin(), m_components.end(), isSameComponent);
}

Component *Entity::getComponent(std::uint64_t key) {
    return *getComponentIterator(key);
}

Entity::Entity() {

}

Entity::Entity(const std::vector<Component *> &components) {
    m_components.reserve(components.size());
    for(auto& component : components){
        addComponent(component);
    }
}

Entity::Entity(std::vector<Component *> &&components) {
   // m_components = std::move(components);
    m_components.reserve(components.size());
    for(auto& component : components){
        addComponent(component);
    }
}


