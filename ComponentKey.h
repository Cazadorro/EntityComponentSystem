//
// Created by Shae Bolt on 3/24/2017.
//

#ifndef UNTITLED_COMPONENTKEY_H
#define UNTITLED_COMPONENTKEY_H
#include <bitset>

#define ONEHOT(index) ComponentKey(1) << (index + 1)

constexpr const uint64_t KEYSIZE = 128;

using ComponentKey = std::bitset<KEYSIZE>;

constexpr auto onehotbit(const uint64_t n) {
    return 1 << (n);
}

bool canUnlock(const ComponentKey& lock,  const ComponentKey& key);


#endif //UNTITLED_COMPONENTKEY_H
