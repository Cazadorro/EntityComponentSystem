//
// Created by shae on 6/26/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_HEALTHNAMENODE_H
#define ENTITYCOMPONENTSYSTEM_HEALTHNAMENODE_H

#include "Node.h"
#include "HealthComponent.h"
#include "NameComponent.h"


class HealthNameNode : public StaticKeyNode<HealthNameNode> {
    HealthComponent *m_health;
    NameComponent *m_name;

public:
    HealthNameNode(Entity &entity);
};


#endif //ENTITYCOMPONENTSYSTEM_HEALTHNAMENODE_H
