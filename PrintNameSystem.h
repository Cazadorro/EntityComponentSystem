//
// Created by shae on 6/27/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_PRINTNAMESYSTEM_H
#define ENTITYCOMPONENTSYSTEM_PRINTNAMESYSTEM_H
#include "System.h"

class PrintNameSystem : public System{
public:
private:
    uint64_t key() override;

    void runOnce() override;

    Observer *createClassObserver() override;

};


#endif //ENTITYCOMPONENTSYSTEM_PRINTNAMESYSTEM_H
