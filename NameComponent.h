//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_NAMECOMPONENT_H
#define ENTITYCOMPONENTSYSTEM_NAMECOMPONENT_H

#include "Component.h"
#include <string>
#include "key.h"

class NameComponent : public StaticKeyComponent<NameComponent>{
public:
    std::string m_name = "";
    NameComponent(const std::string name = "");

};


#endif //ENTITYCOMPONENTSYSTEM_NAMECOMPONENT_H
