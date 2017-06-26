//
// Created by shae on 6/25/17.
//

#include "PositionComponent.h"
#include "key.h"

template<>
const uint64_t StaticKeyComponent<PositionComponent>::m_key = bit(1);

PositionComponent::PositionComponent(const int64_t x, const int64_t y, const int64_t z) : m_x(x), m_y(y),
                                                                                                      m_z(z) {};