//
// Created by daniil on 27.03.19.
//
#include "Army.h"
#include <iostream>

#ifndef GAME_GAME_H
#define GAME_GAME_H

class Game {
public:
    Army *createArmy(ArmyFactory &factory);
};

#endif //GAME_GAME_H
