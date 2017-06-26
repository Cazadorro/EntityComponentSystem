//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_NODE_H
#define ENTITYCOMPONENTSYSTEM_NODE_H

#include "key.h"
#include "Entity.h"
#include <cstdint>

class Node {
    Entity *m_entity;
public:
    Node(Entity &m_entity);

    const Entity *entity() const;

    virtual std::uint64_t key() const = 0;
};

template<class Derived>
class StaticKeyNode : public Node {
public:
    StaticKeyNode(Entity &entity) : Node(entity) {};

    std::uint64_t key() const { return m_key; };

    static std::uint64_t classkey() { return m_key; };

protected:
    const static std::uint64_t m_key;
};


#endif //ENTITYCOMPONENTSYSTEM_NODE_H
