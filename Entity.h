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

    bool operator()(Component *component);

};

class Entity {
    std::vector<Component *> m_components;
    std::uint64_t m_key = 0;
public:
    void addComponent(Component *component);

    void removeComponent(Component *component);

    bool hasComponentKey(Component *component);
.
    std::uint64_t key();

    bool hasKey(std::uint64_t key);

    std::size_t numberOfComponents();
};


#endif //ENTITYCOMPONENTSYSTEM_ENTITY_H
