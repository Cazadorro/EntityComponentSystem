//
// Created by Shae Bolt on 3/24/2017.
//

#include "ComponentKey.h"

bool canUnlock(const ComponentKey& lock,  const ComponentKey& key){
    return (lock & key) == key;
}