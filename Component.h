//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_COMPONENT_H
#define ENTITYCOMPONENTSYSTEM_COMPONENT_H


#include <cstdint>

class Component {
public:
    virtual std::uint64_t key() const = 0;
};

template<class Derived>
class StaticKeyComponent : public Component {
public:
    std::uint64_t key() const { return m_key; };

    static std::uint64_t classkey() { return m_key; };

protected:
    static const std::uint64_t m_key;
};

constexpr std::uint64_t bit(const std::uint64_t n) {
    return static_cast<std::uint64_t>(1) << (n);
}

#endif //ENTITYCOMPONENTSYSTEM_COMPONENT_H
