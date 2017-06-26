//
// Created by shae on 6/25/17.
//

#ifndef ENTITYCOMPONENTSYSTEM_TESTINGUTILITY_H
#define ENTITYCOMPONENTSYSTEM_TESTINGUTILITY_H
#include <string>
#include <iostream>
#include <sstream>
#include <cstdlib>

#define ASSERT_WITH_MSG(cond, msg) do \
{ if (!(cond)) { std::ostringstream str; str << msg; std::cerr << str.str(); std::abort(); } \
} while(0)

#endif //ENTITYCOMPONENTSYSTEM_TESTINGUTILITY_H
