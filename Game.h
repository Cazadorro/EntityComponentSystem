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
#include "System.h"

class Game {
    std::unordered_map<std::uint64_t, Observer *> m_observers;
    std::vector<Entity *> m_entities;
    std::vector<System *> m_systems;

    std::vector<Entity *>::iterator getEntityIterator(Entity &entity);
    std::vector<System *>::iterator getSystemIterator(System *system);
public:
    void addObserver(Observer *observer);

    Observer *findObserver(const std::uint64_t key);

    const Observer *findObserver(const std::uint64_t key) const;

    std::size_t numberOfObservers() const;

    bool hasKey(const std::uint64_t key) const;

    std::size_t numberOfEntities() const;

    void addEntity(Entity &entity);

    void removeEntity(Entity &entity);

    std::size_t numberOfSystems() const;

    void addSystem(System * system);

    void removeSystem(System * system);

    void removeObserver(Observer * observer);

    void runOnce();


};


#endif //ENTITYCOMPONENTSYSTEM_GAME_H
