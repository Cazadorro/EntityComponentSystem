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

    SameComponentChecker(std::uint64_t key);

    bool operator()(Component *component) const;

};

class Entity {
    std::vector<Component *> m_components;
    std::uint64_t m_key = 0;

    std::vector<Component *>::iterator getComponentIterator(Component *component);

    std::vector<Component *>::iterator getComponentIterator(std::uint64_t key);

public:

    Entity();

    Entity(const std::vector<Component *> &components);

    Entity(std::vector<Component *> &&components);

    void addComponent(Component *component);

    void removeComponent(Component *component);

    bool hasComponentKey(Component *component) const;

    std::uint64_t key() const;

    bool hasKey(const uint64_t key) const;

    std::size_t numberOfComponents() const;

    Component *getComponent(std::uint64_t key);

    template<typename Component_T>
    Component_T *getComponent() {
        return static_cast<Component_T *>(getComponent(Component_T::classkey()));
    }

};


#endif //ENTITYCOMPONENTSYSTEM_ENTITY_H
