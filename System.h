//
// Created by shae on 6/26/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_SYSTEM_H
#define ENTITYCOMPONENTSYSTEM_SYSTEM_H

#include <cstdint>
#include "Observer.h"

class System {
protected:
    Observer *m_observer;
public:
    virtual std::uint64_t key() = 0;

    virtual void runOnce() = 0;

    virtual Observer *createClassObserver()= 0;

    void setClassObserver(Observer *observer);

};


#endif //ENTITYCOMPONENTSYSTEM_SYSTEM_H
