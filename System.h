//
// Created by Shae Bolt on 2/28/2017.
//

#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H
#include "Observer.h"
#include "PositionComponent.h"
#include "Entity.h"
#include <iostream>

template <typename DerivedNode>
class System {
public:
    virtual uint64_t getReferenceCount(){return m_reference_counter;};
    virtual void incrementReferenceCount(){++m_reference_counter;};
    virtual void update() = 0;
    uint64_t m_reference_counter;
    std::vector<DerivedNode> m_nodes;
    void registerEntity(Entity &entity) {
        if (entity.doesKeyFit(DerivedNode::getKey())){
            m_nodes.push_back(DerivedNode(entity));
        }
    }
    virtual ~System(){};
private:
};

class PhysicsSystem : public System<PhysicsNode>{
public:
    virtual void update();
private:
};

class InputSystem : public System<InputNode>{
public:
    virtual void update();
private:
};



#endif //UNTITLED_SYSTEM_H
