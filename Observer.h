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

    virtual void unregister(const Entity &entity) = 0;

    virtual bool hasEntity(const Entity &entity) const = 0;

    virtual bool keyMatchesEntity(const Entity &entity) const = 0;

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

    typename std::vector<Node_T>::iterator getNodeIterator(const Entity &entity) {
        SameNodeChecker isSameEntity(entity);
        return std::find_if(m_nodes.begin(), m_nodes.end(), isSameEntity);
    }

//    typename std::vector<Node_T>::iterator getNodeIterator(const Entity &entity) const {
//        SameNodeChecker isSameEntity(entity);
//        return std::find_if(m_nodes.begin(), m_nodes.end(), isSameEntity);
//    }

public:

    typename std::vector<Node_T>::iterator begin() {
        return m_nodes.begin();
    }

    typename std::vector<Node_T>::iterator end() {
        return m_nodes.end();
    }

    void remove(const Entity &entity) {
        auto erase_itr = getNodeIterator(entity);
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

    bool hasEntity(const Entity &entity) const {
        SameNodeChecker isSameEntity(entity);
        return std::find_if(m_nodes.begin(), m_nodes.end(), isSameEntity) != m_nodes.end();
    }

    bool keyMatchesEntity(const Entity &entity) const {
        return entity.hasKey(Node_T::classkey());
    }

    //TODO may need to increase performance of entity search for removal
    void unregister(const Entity &entity) {
        if (keyMatchesEntity(entity)) {
            remove(entity);
        }
    }

    std::uint64_t key() const { return Node_T::classkey(); };

    static std::uint64_t classkey() { return Node_T::classkey(); };

};

#endif //ENTITYCOMPONENTSYSTEM_OBSERVER_H