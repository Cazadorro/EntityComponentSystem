//
// Created by shae on 6/25/17.
//

#include "UnitTests.h"
#include "cassert"
#include <bitset>

void addComponentTest(Entity &entity, Component *component) {
    entity.addComponent(component);
    assert((entity.key() & component->key(), "Error, entity does not contain component key"));

}

void addSameComponentTest() {
    Component component1;
    Component* component = & component1;
    Entity entity;
    auto previous_size = entity.numberOfComponents();
    assert((std::bitset<64>(entity.key()).count() == 0, "Error, number of bits set is not zero"));
    addComponentTest(entity, component);
    assert((std::bitset<64>(entity.key()).count() == 1, "Error, number of bits set is not one"));
    assert(((previous_size + 1) == entity.numberOfComponents(), "Error, entity didn't properly add component"));
    previous_size = entity.numberOfComponents();
    addComponentTest(entity, component);
    assert(((previous_size) ==
            entity.numberOfComponents(), "Error, entity should have same size if adding same type of component"));
    assert((std::bitset<64>(entity.key()).count() == 1, "Error, number of bits set is not one"));
}
