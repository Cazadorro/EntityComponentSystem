//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_ENTITY_H
#define ENTITYCOMPONENTSYSTEM_ENTITY_H

#include "Component.h"
#include <vector>


class SameComponentChecker {
    std::uint64_t m_key = 0;
public:
    SameComponentChecker(Component *component);

    bool operator()(Component *component) const;

};

class Entity {
    std::vector<Component *> m_components;
    std::uint64_t m_key = 0;
public:
    void addComponent(Component *component);

    void removeComponent(Component *component);

    bool hasComponentKey(Component *component) const;

    std::uint64_t key() const;

    bool hasKey(std::uint64_t key)const;

    std::size_t numberOfComponents()const;
};


#endif //ENTITYCOMPONENTSYSTEM_ENTITY_H
