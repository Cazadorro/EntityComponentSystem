//
// Created by Shae Bolt on 2/28/2017.
//

#ifndef UNTITLED_OBSERVER_H
#define UNTITLED_OBSERVER_H
#include "ComponentNode.h"
#include <stdint.h>
#include <vector>
#include "ComponentKey.h"

//TODO make observer types singletons and templated
class Observer{
public:
    ComponentKey m_key;
    uint64_t m_reference_count;
    std::vector<ComponentNode*> m_observed_nodes;
    virtual ~Observer(){};
private:
};


#endif //UNTITLED_OBSERVER_H
