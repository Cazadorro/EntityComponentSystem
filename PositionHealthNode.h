//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_POSITIONHEALTHNODE_H
#define ENTITYCOMPONENTSYSTEM_POSITIONHEALTHNODE_H

#include "Node.h"
#include "PositionComponent.h"
#include "HealthComponent.h"

class PositionHealthNode : public StaticKeyNode<PositionHealthNode> {
    PositionComponent *m_position_component;
    HealthComponent *m_health_component;
public:
    PositionHealthNode(Entity &entity);


};


#endif //ENTITYCOMPONENTSYSTEM_POSITIONHEALTHNODE_H
