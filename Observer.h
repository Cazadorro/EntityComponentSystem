//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_OBSERVER_H
#define ENTITYCOMPONENTSYSTEM_OBSERVER_H

#include "Entity.h"
#include <cstddef>
#include <vector>
#include <algorithm>
#include <boost/assert.hpp>
#include "Node.h"

class Observer {
public:
    virtual std::size_t numberOfEntities() const = 0;

    virtual void registerNew(Entity &entity) = 0;

    virtual std::uint64_t key() const = 0;
};

class SameNodeChecker {
    Entity const *m_entity;
public:
    SameNodeChecker(const Entity &entity);

    bool operator()(const Node &node) const;
};

template<class Node_T>
class NodeObserver : public Observer {
    std::vector<Node_T> m_nodes;
public:

    typename std::vector<Node_T>::iterator begin() {
        return m_nodes.begin();
    }

    typename std::vector<Node_T>::iterator end() {
        return m_nodes.end();
    }

    void remove(const Entity &entity) {
        SameNodeChecker isSameEntity(entity);
        auto erase_itr = std::find_if(m_nodes.begin(), m_nodes.end(), isSameEntity);
        BOOST_ASSERT_MSG(erase_itr != m_nodes.end(), "at end!");
        m_nodes.erase(erase_itr);
    }

    std::size_t numberOfEntities() const {
        return m_nodes.size();
    }

    void registerNew(Entity &entity) {
        if (entity.hasKey(Node_T::classkey())) {
            m_nodes.push_back(Node_T(entity));
        }
    }

    std::uint64_t key() const { return Node_T::classkey(); };

    static std::uint64_t classkey() { return Node_T::classkey(); };

};

#endif //ENTITYCOMPONENTSYSTEM_OBSERVER_H