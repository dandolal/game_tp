//
// Created by daniil on 27.03.19.
//

#include <iostream>
#include <vector>
#include "wariors.h"


#ifndef GAME_ARMY_H
#define GAME_ARMY_H

class Army {
public:
    Army() {
        cost.resize(3);
        cost[0] = 1;
        cost[1] = 100;
        cost[2] = 50;
    }

    ~Army();

    void info();

    void AddInfantryUnit(Infantryunit *unit);

    void AddTankUnit(Tankunit *unit);

    void AddTowerUnit(Towerunit *unit);

    void SetMoney(int money_);

    void SetType(char type_);

    void FindInfantryUnit(int i, Infantryunit *&unit);

    void FindTankUnit(int i, Tankunit *&unit);

    void FindTowerUnit(int i, Towerunit *&unit);

private:
    std::vector<int> cost;
    std::vector<Infantryunit *> infantry;
    std::vector<Tankunit *> tanks;
    std::vector<Towerunit *> towers;
    int money;
    char type;
};

class ArmyFactory {
public:
    ArmyFactory(int n, char type_) {
        money = n;
        type = type_;
    }

    virtual void createInfantryunit(Infantryunit *&unit) = 0;

    virtual void createTankunit(Tankunit *&unit) = 0;

    virtual void createTowerunit(Towerunit *&unit) = 0;

    virtual ~ArmyFactory() {}

    int GetMoney();

    char GetType();

protected:
    int money;
    char type;
};

class WhiteArmyFactory : public ArmyFactory {
public:
    WhiteArmyFactory() : ArmyFactory(200000, 'w') {}

    void createInfantryunit(Infantryunit *&unit);

    void createTankunit(Tankunit *&unit);

    void createTowerunit(Towerunit *&unit);
};

class BlackArmyFactory : public ArmyFactory {
public:
    BlackArmyFactory() : ArmyFactory(100000, 'b') {}

    void createInfantryunit(Infantryunit *&unit);

    void createTankunit(Tankunit *&unit);

    void createTowerunit(Towerunit *&unit);

    void createOppositeInfantryunit(Infantryunit *&unit, Infantryunit *&unit1);

    void createOppositeTankunit(Tankunit *&unit, Tankunit *&unit1);

    void createOppositeTowerunit(Towerunit *&unit, Towerunit *&unit1);
};

#endif //GAME_ARMY_H
