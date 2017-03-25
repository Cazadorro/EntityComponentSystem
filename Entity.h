//
// Created by Shae Bolt on 2/28/2017.
//

#ifndef UNTITLED_ENTITY_H
#define UNTITLED_ENTITY_H

#include <stdint.h>
#include "Component.h"
#include <forward_list>
#include <vector>
#include "ComponentKey.h"

class Entity {
    //TODO need to singltonize here?
public:
    Entity *m_parent_ptr;
    //TODO handle this?
    //static last used id?
    uint64_t m_id;
    ComponentKey m_lock = 0;
    std::forward_list<Component *> m_components;
    std::forward_list<Component *> m_entities;

    void addComponent(Component *component);

    void removeComponent(const ComponentKey &componentID);

    Component *getComponent(const ComponentKey &componentIDs);

    bool doesKeyFit(const ComponentKey& key) const;
    virtual ~Entity(){};
protected:
    std::forward_list<Component *>::iterator findComponent(const ComponentKey &
    componentID);
};


#endif //UNTITLED_ENTITY_H
