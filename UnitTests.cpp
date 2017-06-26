//
// Created by shae on 6/25/17.
//

#include "UnitTests.h"
#include "cassert"
#include <bitset>
#include <string>
#include "PositionComponent.h"
#include "HealthComponent.h"
#include "boost/assert.hpp"
#include "testingutility.h"
#include "PositionHealthNode.h"
#include "NamePositionNode.h"
#include "HealthNameNode.h"
#include "Observer.h"
#include "Game.h"

void assertCount(const std::uint64_t key, const size_t count) {
    size_t actual_count = std::bitset<64>(key).count();
    std::string assert_failure_message =
            "Error, key bits set : " + std::to_string(actual_count) + " != expected bits set " + std::to_string(count);
    ASSERT_WITH_MSG(actual_count == count, assert_failure_message);
}

void assertContainsKey(const Entity &entity, const Component *component) {
    std::string assert_failure_message =
            "Error, entity key : " + std::bitset<64>(entity.key()).to_string() + " does not contain key : " +
            std::bitset<64>(component->key()).to_string();
    ASSERT_WITH_MSG(entity.key() & component->key(), assert_failure_message.c_str());
}

void assertNumberOfComponents(const Entity &entity, const std::size_t size) {
    std::string assert_failure_message =
            "Error number of components : " + std::to_string(entity.numberOfComponents()) + " != " +
            std::to_string(size);
    ASSERT_WITH_MSG(entity.numberOfComponents() == size, assert_failure_message.c_str());
}

void assertNumberOfNodes(const Observer &observer, const std::size_t size) {
    std::string assert_failure_message =
            "Error number of entries : " + std::to_string(observer.numberOfEntities()) + " != " +
            std::to_string(size);
    ASSERT_WITH_MSG(observer.numberOfEntities() == size, assert_failure_message.c_str());
}

void assertGameHasObserver(const Game &game, const Observer *observer) {
    std::string assert_failure_message = "Error, Game does not contain observer key " + std::to_string(observer->key());
    ASSERT_WITH_MSG(game.hasKey(observer->key()), assert_failure_message.c_str());
}

void assertGameObserverLength(const Game &game, const std::size_t size) {
    std::string assert_failure_message =
            "Error, number of entries " + std::to_string(game.numberOfObservers()) + " != " + std::to_string(size);
    ASSERT_WITH_MSG(game.numberOfObservers() == size, assert_failure_message.c_str());
}

void assertGameHasNEntities(const Game &game, const std::size_t size) {
    std::string assert_failure_message =
            "Error, number of entities " + std::to_string(game.numberOfEntities()) + " != " + std::to_string(size);
    ASSERT_WITH_MSG(game.numberOfEntities() == size, assert_failure_message.c_str());
}

void addComponentTest(Entity &entity, Component *component) {
    entity.addComponent(component);
    assertContainsKey(entity, component);

}

void addSameComponentTest() {
    HealthComponent component1;
    Component *component = &component1;
    Entity entity;
    auto previous_size = entity.numberOfComponents();
    assertCount(entity.key(), 0);
    addComponentTest(entity, component);
    assertCount(entity.key(), 1);
    assertNumberOfComponents(entity, previous_size + 1);
    previous_size = entity.numberOfComponents();
    addComponentTest(entity, component);
    assertNumberOfComponents(entity, previous_size);
    assertCount(entity.key(), 1);
}

void addMultiComponentTest() {
    Component *c_1 = new PositionComponent();
    Component *c_2 = new HealthComponent();
    Entity entity;

    addComponentTest(entity, c_1);
    addComponentTest(entity, c_2);
    assertCount(entity.key(), 2);
    assertNumberOfComponents(entity, 2);

    delete c_1;
    delete c_2;
}

void observerAddBlankTest() {
    Entity entity;
    NodeObserver<PositionHealthNode> observer;
    observer.registerNew(entity);
    ASSERT_WITH_MSG(observer.numberOfEntities() == 0, "Error number of entities should be none");
}

void observerAddMultipleTest() {
    Entity e1;
    Entity e2;
    Entity e3;
    PositionComponent *p1 = new PositionComponent();
    PositionComponent *p2 = new PositionComponent();
    PositionComponent *p3 = new PositionComponent();
    HealthComponent *h1 = new HealthComponent();
    HealthComponent *h2 = new HealthComponent();
    HealthComponent *h3 = new HealthComponent();

    e1.addComponent(p1);
    e1.addComponent(h1);
    e2.addComponent(h2);
    e2.addComponent(p2);
    e3.addComponent(h3);
    e3.addComponent(p3);

    assertCount(PositionHealthNode::classkey(), 2);

    NodeObserver<PositionHealthNode> observer;
    assertCount(observer.key(), 2);

    assertNumberOfNodes(observer, 0);

    observer.registerNew(e1);
    assertNumberOfNodes(observer, 1);
    observer.registerNew(e2);
    assertNumberOfNodes(observer, 2);
    observer.registerNew(e3);
    assertNumberOfNodes(observer, 3);

    delete p1, p2, p3, h1, h2, h3;
}

void initEntityWithComponents() {

    PositionComponent *p1 = new PositionComponent();
    HealthComponent *h1 = new HealthComponent();
    Entity e1({p1, h1});
    assertCount(e1.key(), 2);
    assertContainsKey(e1, p1);
    assertContainsKey(e1, h1);
    NodeObserver<PositionHealthNode> observer;
    observer.registerNew(e1);
    assertNumberOfNodes(observer, 1);
    delete p1, h1;
    std::cerr << "Deal have not dealt with deletion within entity" << std::endl;
}

void gameobserverListTest() {
    NodeObserver<NamePositionNode> o1;
    NodeObserver<PositionHealthNode> o2;
    NodeObserver<HealthNameNode> o3;

    Game game;

    game.addObserver(&o1);
    game.addObserver(&o2);
    game.addObserver(&o3);

    assertGameHasObserver(game, &o1);
    assertGameHasObserver(game, &o2);
    assertGameHasObserver(game, &o3);
    assertGameObserverLength(game, 3);

    std::cerr << "Deal have not dealt with deletion within game for m_observers" << std::endl;
}

void gameEntityAddRemoveTest() {

    PositionComponent *p1 = new PositionComponent();
    PositionComponent *p2 = new PositionComponent();
    PositionComponent *p3 = new PositionComponent();
    HealthComponent *h1 = new HealthComponent();
    HealthComponent *h2 = new HealthComponent();
    HealthComponent *h3 = new HealthComponent();
    NameComponent *n1 = new NameComponent();
    NameComponent *n2 = new NameComponent();
    NameComponent *n3 = new NameComponent();

    Entity e1({p1, h1, n1});
    Entity e2({p2, h2, n2});
    Entity e3({p3, h3, n3});

    Game game;

    game.addEntity(e1);
    game.addEntity(e2);
    game.addEntity(e3);

    assertGameHasNEntities(game, 3);

    game.removeEntity(e1);
    game.removeEntity(e2);
    game.removeEntity(e3);

    assertGameHasNEntities(game, 0);
}
