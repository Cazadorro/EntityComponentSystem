//
// Created by shae on 6/25/17.
//

#include "NameComponent.h"

template<>
const uint64_t StaticKeyComponent<NameComponent>::m_key = bit(3);

NameComponent::NameComponent(const std::string name) {
    m_name = name;
}
