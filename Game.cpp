//
// Created by shae on 6/26/17.
//

#include "Game.h"

void Game::addObserver(Observer *observer) {
    m_observers.insert(std::pair<std::uint64_t, Observer *>(observer->key(), observer));
}

const Observer *Game::findObserver(const std::uint64_t key) const {
    auto find_itr = m_observers.find(key);
    return find_itr != m_observers.end() ? (*find_itr).second : nullptr;
}

Observer *Game::findObserver(const std::uint64_t key) {
    auto find_itr = m_observers.find(key);
    return find_itr != m_observers.end() ? (*find_itr).second : nullptr;
}

std::size_t Game::numberOfObservers() const {
    return m_observers.size();
}

bool Game::hasKey(const std::uint64_t key) const {
    return m_observers.find(key) != m_observers.end();
}

std::size_t Game::numberOfEntities() const {
    return m_entities.size();
}

void Game::addEntity(Entity &entity) {
    m_entities.push_back(&entity);
    for (auto &observer: m_observers) {
        observer.second->registerNew(entity);
    }
}

void Game::removeEntity(Entity &entity) {
    auto entity_itr = getEntityIterator(entity);
    for (auto &observer: m_observers) {
        observer.second->unregister(entity);
    }
    if (entity_itr != m_entities.end()) {
        m_entities.erase(entity_itr);
    }
}

std::vector<Entity *>::iterator Game::getEntityIterator(Entity &entity) {
    return std::find(m_entities.begin(), m_entities.end(), &entity);
}

std::vector<System *>::iterator Game::getSystemIterator(System *system) {
    return std::find(m_systems.begin(), m_systems.end(), system);
}

std::size_t Game::numberOfSystems() const {
    return m_systems.size();
}

void Game::addSystem(System *system) {
    m_systems.push_back(system);
    if(!hasKey(system->key())){
        addObserver(system->createClassObserver());
    }
    system->setClassObserver(findObserver(system->key()));
}


void Game::removeSystem(System *system) {
    m_systems.erase(getSystemIterator(system));
}

void Game::removeObserver(Observer *observer) {
    m_observers.erase(m_observers.find(observer->key()));
}

void Game::runOnce() {
    for(auto system : m_systems){
        (*system).runOnce();
    }
}


