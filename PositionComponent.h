//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_POSITIONCOMPONENT_H
#define ENTITYCOMPONENTSYSTEM_POSITIONCOMPONENT_H

#include "Component.h"

class PositionComponent : public StaticKeyComponent<PositionComponent> {

public:
    int64_t m_x;
    int64_t m_y;
    int64_t m_z;
    PositionComponent(const int64_t x = 0, const int64_t y = 0, const int64_t z = 0);
};


#endif //ENTITYCOMPONENTSYSTEM_POSITIONCOMPONENT_H
