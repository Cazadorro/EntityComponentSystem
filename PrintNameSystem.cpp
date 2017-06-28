//
// Created by shae on 6/27/17.
//

#include "PrintNameSystem.h"
#include "NameNode.h"
#include "Observer.h"
#include <iostream>

uint64_t PrintNameSystem::key() {
    return NameNode::classkey();
}

void PrintNameSystem::runOnce() {
    for(auto node : *static_cast<NodeObserver<NameNode>*>(m_observer)){
        std::cout << node.getName() << std::endl;
    }

}

Observer *PrintNameSystem::createClassObserver() {
    return new NodeObserver<NameNode>();
}