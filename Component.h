//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_COMPONENT_H
#define ENTITYCOMPONENTSYSTEM_COMPONENT_H

#include "key.h"
#include <cstdint>

class Component {
public:
    virtual std::uint64_t key() const = 0;
};

template<class Derived>
class StaticKeyComponent : public Component {
public:
    std::uint64_t key() const override { return m_key; };

    static std::uint64_t classkey() { return m_key; };

protected:
    static const std::uint64_t m_key;
};


#endif //ENTITYCOMPONENTSYSTEM_COMPONENT_H
