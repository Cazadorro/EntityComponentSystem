//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_HEALTHCOMPONENT_H
#define ENTITYCOMPONENTSYSTEM_HEALTHCOMPONENT_H

#include "Component.h"

class HealthComponent : public StaticKeyComponent<HealthComponent> {
public:
    std::uint64_t m_health;

    HealthComponent(const std::uint64_t health = 0) : m_health(health) {};

};


#endif //ENTITYCOMPONENTSYSTEM_HEALTHCOMPONENT_H
