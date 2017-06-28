//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_NAMEPOSITIONCOMPONENT_H
#define ENTITYCOMPONENTSYSTEM_NAMEPOSITIONCOMPONENT_H

#include "Node.h"
#include "NameComponent.h"
#include "PositionComponent.h"

class NamePositionNode : public StaticKeyNode<NamePositionNode> {
    NameComponent *m_name_component;
    PositionComponent *m_position_component;
public:
    NamePositionNode(Entity& entity);

};


#endif //ENTITYCOMPONENTSYSTEM_NAMEPOSITIONCOMPONENT_H
