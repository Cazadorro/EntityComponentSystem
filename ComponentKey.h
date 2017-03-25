//
// Created by Shae Bolt on 3/24/2017.
//

#ifndef UNTITLED_COMPONENTKEY_H
#define UNTITLED_COMPONENTKEY_H
#include <bitset>

#define ONEHOT(index) ComponentKey(1) << (index + 1)

constexpr const uint64_t KEYSIZE = 128;

using ComponentKey = std::bitset<KEYSIZE>;

//constexpr ComponentKey bit(const uint64_t n) {
//    return static_cast<ComponentKey>(1) << (n);
//}

//constexpr ComponentKey bit(const uint64_t n){
//    return ComponentKey(bit_().replace(n,1,"1"));
//}

bool canUnlock(const ComponentKey& lock,  const ComponentKey& key);


#endif //UNTITLED_COMPONENTKEY_H
