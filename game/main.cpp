#include <iostream>
#include "game.h"
#include <string>


int main() {
    Game game;
    WhiteArmyFactory w_factory;
    BlackArmyFactory b_factory;

    Army *wa = game.createArmy(w_factory);
    Army *ba = game.createArmy(b_factory);
    Towerunit *twunit;
    w_factory.createTowerunit(twunit);
    wa->AddTowerUnit(twunit);
    b_factory.createTowerunit(twunit);
    wa->AddTowerUnit(twunit);
    Towerunit *twunit1;
    wa->FindTowerUnit(10, twunit1);
    b_factory.createOppositeTowerunit(twunit, twunit1);
    std::cout << "White army:" << std::endl;
    wa->info();
    std::cout << "\nBlack army:" << std::endl;
    ba->info();


    // ...
}