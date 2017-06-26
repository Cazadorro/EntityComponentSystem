//
// Created by shae on 6/26/17.
//

#include "Game.h"

void Game::addObserver(Observer *observer) {
    m_observers.insert(std::pair<std::uint64_t, Observer *>(observer->key(), observer));
}

const Observer *Game::find(const std::uint64_t key) const {
    auto find_itr = m_observers.find(key);
    return find_itr != m_observers.end() ? (*find_itr).second : nullptr;
}

Observer *Game::find(const std::uint64_t key) {
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
}

void Game::removeEntity(Entity &entity) {
    auto entity_itr = getComponentIterator(entity);
    if (entity_itr != m_entities.end()) {
        m_entities.erase(entity_itr);
    }
}

std::vector<Entity *>::iterator Game::getComponentIterator(Entity &entity) {
    SameEntityChecker isSameEntity(&entity);
    return std::find_if(m_entities.begin(), m_entities.end(), isSameEntity);
}

SameEntityChecker::SameEntityChecker(Entity *entity) {
    m_entity = entity;
}

bool SameEntityChecker::operator()(Entity *entity) const {
    return m_entity == entity;
}
