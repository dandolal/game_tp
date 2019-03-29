//
// Created by daniil on 29.03.19.
//
#include <iostream>
#include "game.h"
#include "wariors.h"
#include "Army.h"
#include "googletest-master/googletest/include/gtest/gtest.h"

TEST (TestGroup1, Test1){
    WhiteArmyFactory w_factory;
    Towerunit *twunit;
    for (int i = 0; i < 1000; ++i)
        w_factory.createTowerunit(twunit);
}

TEST(TestGroup1, Test2){
    Game game;
    WhiteArmyFactory w_factory;
    Army *wa = game.createArmy(w_factory);
    Towerunit *twunit;
    for (int i = 0; i < 1000; ++i){
        w_factory.createTowerunit(twunit);
        wa->AddTowerUnit(twunit);
    }
}

TEST (TestGroup1, Test3){
    BlackArmyFactory b_factory;
    Towerunit *twunit;
    for (int i = 0; i < 1000; ++i)
        b_factory.createTowerunit(twunit);
}

TEST(TestGroup1, Test4){
    Game game;
    BlackArmyFactory b_factory;
    Army *ba = game.createArmy(b_factory);
    Towerunit *twunit;
    for (int i = 0; i < 1000; ++i){
        b_factory.createTowerunit(twunit);
        ba->AddTowerUnit(twunit);
    }
}


