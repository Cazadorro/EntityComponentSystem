//
// Created by Shae Bolt on 2/28/2017.
//

#ifndef UNTITLED_SYSTEM_H
#define UNTITLED_SYSTEM_H
#include "Observer.h"
#include "PositionComponent.h"
#include "Entity.h"
#include <iostream>
#include <algorithm>

class System {
public:
    virtual uint64_t getReferenceCount(){return m_reference_counter;};
    virtual void incrementReferenceCount(){++m_reference_counter;};
    virtual void update() = 0;
    uint64_t m_reference_counter;
    virtual void registerEntity(Entity &entity)= 0;
    virtual ~System(){};
private:
};

template <typename DerivedNode>
class SystemWithRegister : public System{
public:
    std::vector<DerivedNode> m_nodes;
    void registerEntity(Entity &entity) {
        if (entity.doesKeyFit(DerivedNode::getKey())){
            m_nodes.push_back(DerivedNode(entity));
        }
    }
    virtual ~SystemWithRegister(){};
private:
};

class PhysicsSystem : public SystemWithRegister<PhysicsNode>{
public:
    virtual void update();
private:
};

class InputSystem : public SystemWithRegister<InputNode>{
public:
    virtual void update();
private:
};

class DisplaySystem : public SystemWithRegister<DisplayNode>{
public:
    virtual void update();
private:
};


#endif //UNTITLED_SYSTEM_H
