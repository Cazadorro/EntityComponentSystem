//
// Created by shae on 6/25/17.
//

#ifndef TESTCOMPONENTSYSTEM_UNITTESTS_H
#define TESTCOMPONENTSYSTEM_UNITTESTS_H

#include "Entity.h"
#include "Component.h"

void addComponentTest(Entity &entity, Component *component);

void addSameComponentTest();

void addMultiComponentTest();

void observerAddBlankTest();

void observerAddMultipleTest();

void initEntityWithComponents();

void gameobserverListTest();

void gameEntityAddRemoveTest();

void gameEntityAddRemoveToObserverTest();


#endif //TESTCOMPONENTSYSTEM_UNITTESTS_H
