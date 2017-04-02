//
// Created by Shae Bolt on 2/28/2017.
//

#ifndef UNTITLED_COMPONENT_H
#define UNTITLED_COMPONENT_H
#include <stdint.h>
#include "ComponentKey.h"
#include <vector>

class Component {
public:
    virtual ComponentKey getKey()const = 0;
    virtual ~Component(){};
};

template<class Derived>
class ComponentWithKey : public Component{
public:
    virtual ComponentKey getKey()const{return m_key;};
    static ComponentKey getClassKey() {return m_key;};
protected:
    static const ComponentKey m_key;
};

//template<class Derived>
//class ComponentWithPool : public Component{
//public:
//
//protected:
//    static std::vector<Derived> m_pool;
//};


#endif //UNTITLED_COMPONENT_H
