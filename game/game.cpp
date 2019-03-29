//
// Created by daniil on 28.03.19.
//
#include "game.h"

Army *Game::createArmy(ArmyFactory &factory) {
    Army *army = new Army;
    army->SetType(factory.GetType());
    army->SetMoney(factory.GetMoney());
    Infantryunit *inunit;
    factory.createInfantryunit(inunit);
    army->AddInfantryUnit(inunit);
    Tankunit *tnunit;
    factory.createTankunit(tnunit);
    army->AddTankUnit(tnunit);
    Towerunit *twunit;
    factory.createTowerunit(twunit);
    army->AddTowerUnit(twunit);
    return army;
}