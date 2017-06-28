//
// Created by shae on 6/27/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_NAMENODE_H
#define ENTITYCOMPONENTSYSTEM_NAMENODE_H

#include "Node.h"
#include "NameComponent.h"

class NameNode : public StaticKeyNode<NameNode> {
    NameComponent *m_name_component;
public:

    NameNode(Entity &entity);
    std::string getName() const;

};


#endif //ENTITYCOMPONENTSYSTEM_NAMENODE_H
