//
// Created by shae on 6/25/17.
//

#include "UnitTests.h"
#include "iostream"

int main() {
    addSameComponentTest();
    addMultiComponentTest();
    observerAddBlankTest();
    observerAddMultipleTest();
    initEntityWithComponents();
    gameobserverListTest();
    gameEntityAddRemoveTest();
    gameEntityAddRemoveToObserverTest();
    gameAddSystemTest();
    gameSystemModifyTest();
    return 0;
}