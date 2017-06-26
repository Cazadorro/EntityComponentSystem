//
// Created by shae on 6/26/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_GAME_H
#define ENTITYCOMPONENTSYSTEM_GAME_H

#include "Entity.h"
#include "Observer.h"
#include <cstdint>
#include <unordered_map>
#include <vector>

class SameEntityChecker {
    Entity * m_entity;
public:
    SameEntityChecker(Entity *entity);

    bool operator()(Entity *entity) const;

};

class Game {
    std::unordered_map<std::uint64_t, Observer *> m_observers;
    std::vector<Entity *> m_entities;

    std::vector<Entity *>::iterator getComponentIterator(Entity & entity);
public:
    void addObserver(Observer *observer);

    Observer *find(const std::uint64_t key);

    const Observer *find(const std::uint64_t key) const;

    std::size_t numberOfObservers() const;

    bool hasKey(const std::uint64_t key) const;

    std::size_t numberOfEntities() const;

    void addEntity(Entity &entity);

    void removeEntity(Entity &entity);
};


#endif //ENTITYCOMPONENTSYSTEM_GAME_H
