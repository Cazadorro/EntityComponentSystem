//
// Created by Shae Bolt on 2/28/2017.
//

#include "Entity.h"

void Entity::addComponent(Component *component) {
    m_components.push_front(component);
    m_lock |= component->getKey();
}

void Entity::removeComponent(const ComponentKey &componentID) {
    auto iter = findComponent(componentID);
    (*iter)->kill();
    m_components.erase_after(iter);
}

Component * Entity::getComponent(const ComponentKey &componentID) {
    return *findComponent(componentID);
}

std::forward_list<Component *>::iterator Entity::findComponent(const ComponentKey &
componentID) {
    for (auto iter = m_components.begin(); iter != m_components.end(); ++iter) {
        if ((*iter)->getKey() == componentID) {
            return iter;
        }
    }
    return m_components.end();
}

bool Entity::doesKeyFit(const ComponentKey& key)const {
    return canUnlock(m_lock, key);
}
