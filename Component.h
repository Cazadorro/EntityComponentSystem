//
// Created by Shae Bolt on 2/28/2017.
//

#ifndef UNTITLED_COMPONENT_H
#define UNTITLED_COMPONENT_H
#include <stdint.h>
#include "ComponentKey.h"

class Component {
public:

    virtual bool isAlive() const {
        return m_alive;
    };
    virtual void kill(){
        m_alive = false;
    };
    virtual ComponentKey getKey()const = 0;
    virtual ~Component(){};
protected:
    bool m_alive;
};

template<class Derived>
class ComponentWithKey : public Component{
public:
    virtual ComponentKey getKey()const{return m_key;};
    static ComponentKey getClassKey() {return m_key;};
protected:
    static const ComponentKey m_key;
};


#endif //UNTITLED_COMPONENT_H
