//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_KEY_H
#define ENTITYCOMPONENTSYSTEM_KEY_H
#include <cstdint>

constexpr std::uint64_t bit(const std::uint64_t n) {
    return static_cast<std::uint64_t>(1) << (n);
}

#endif //ENTITYCOMPONENTSYSTEM_KEY_H
