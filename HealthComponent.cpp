//
// Created by shae on 6/25/17.
//

#include "HealthComponent.h"
#include "key.h"

template <>
const uint64_t StaticKeyComponent<HealthComponent>::m_key = bit(2);

HealthComponent::HealthComponent(const std::uint64_t health) : m_health(health) {};