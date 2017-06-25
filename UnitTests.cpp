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

void assertCount(const std::uint64_t key, const size_t count) {
    size_t actual_count = std::bitset<64>(key).count();
    std::string assert_failure_message =
            "Error, key bits set : " + std::to_string(actual_count) + " != expected bits set " + std::to_string(count);
    BOOST_ASSERT_MSG(actual_count == count, assert_failure_message.c_str());
}

void assertContainsKey(const Entity &entity, const Component *component) {
    std::string assert_failure_message =
            "Error, entity key : " + std::bitset<64>(entity.key()).to_string() + " does not contain key : " +
            std::bitset<64>(component->key()).to_string();
    BOOST_ASSERT_MSG(entity.key() & component->key(), assert_failure_message.c_str());
}

void assertNumberOfComponents(const Entity &entity, const std::size_t size) {
    std::string assert_failure_message =
            "Error number of components : " + std::to_string(entity.numberOfComponents()) + " != " +
            std::to_string(size);
    BOOST_ASSERT_MSG(entity.numberOfComponents() == size, assert_failure_message.c_str());
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
