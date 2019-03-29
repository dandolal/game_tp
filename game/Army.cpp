//
// Created by daniil on 28.03.19.
//
#include <iostream>
#include "Army.h"

Army::~Army() {
    int i;
    for (i = 0; i < infantry.size(); ++i) delete infantry[i];
    for (i = 0; i < tanks.size(); ++i) delete tanks[i];
    for (i = 0; i < towers.size(); ++i) delete towers[i];
}

void Army::info() {
    for (int i = 0; i < infantry.size(); ++i) infantry[i]->info();
    for (int i = 0; i < tanks.size(); ++i) tanks[i]->info();
    for (int i = 0; i < towers.size(); ++i) towers[i]->info();
    std::cout << "Your money " << money << std::endl;
}

void Army::AddInfantryUnit(Infantryunit *unit) {
    if (unit->GetType() != type) {
        std::cout << "You can't add unit of this color" << std::endl;
        delete unit;
        return;
    }
    if (money < cost[0]) {
        std::cout << "You don't have enough money" << std::endl;
        delete unit;
        return;
    }
    infantry.push_back(unit);
    money -= cost[0];
}

void Army::AddTankUnit(Tankunit *unit) {
    if (unit->GetType() != type) {
        std::cout << "You can't add unit of this color" << std::endl;
        delete unit;
        return;
    }
    if (money < cost[1]) {
        std::cout << "You don't have enough money" << std::endl;
        delete unit;
        return;
    }
    tanks.push_back(unit);
    money -= cost[1];
}

void Army::AddTowerUnit(Towerunit *unit) {
    if (unit->GetType() != type) {
        std::cout << "You can't add unit of this color" << std::endl;
        delete unit;
        return;
    }
    if (money < cost[2]) {
        std::cout << "You don't have enough money" << std::endl;
        delete unit;
        return;
    }
    towers.push_back(unit);
    money -= cost[2];
}

void Army::SetMoney(int money_) {
    money = money_;
}

void Army::SetType(char type_) {
    type = type_;
}

void Army::FindInfantryUnit(int i, Infantryunit *&unit) {
    if (i >= infantry.size()) {
        std::cout << "No such Unit" << std::endl;
        unit = nullptr;
        return;
    } else
        unit = infantry[i];
}

void Army::FindTankUnit(int i, Tankunit *&unit) {
    if (i >= tanks.size()) {
        std::cout << "No such Unit" << std::endl;
        unit = nullptr;
        return;
    } else
        unit = tanks[i];
}

void Army::FindTowerUnit(int i, Towerunit *&unit) {
    if (i >= towers.size()) {
        std::cout << "No such Unit" << std::endl;
        unit = nullptr;
        return;
    } else
        unit = towers[i];
}

int ArmyFactory::GetMoney() {
    return money;
}

char ArmyFactory::GetType() {
    return type;
}

void WhiteArmyFactory::createInfantryunit(Infantryunit *&unit) {
    unit = new WhiteInfantryunit;
    unit->SetType(type);
}

void WhiteArmyFactory::createTankunit(Tankunit *&unit) {
    unit = new WhiteTankunit;
    unit->SetType(type);
}

void WhiteArmyFactory::createTowerunit(Towerunit *&unit) {
    unit = new WhiteTowerunit;
    unit->SetType(type);
}

void BlackArmyFactory::createInfantryunit(Infantryunit *&unit) {
    unit = new BlackInfantryunit;
    unit->SetType(type);
}

void BlackArmyFactory::createTankunit(Tankunit *&unit) {
    unit = new BlackTankunit;
    unit->SetType(type);
}

void BlackArmyFactory::createTowerunit(Towerunit *&unit) {
    unit = new BlackTowerunit;
    unit->SetType(type);
}

void BlackArmyFactory::createOppositeInfantryunit(Infantryunit *&unit, Infantryunit *&unit1) {
    if (unit1 == nullptr) {
        std::cout << "You are trying to create unit from emptiness" << std::endl;
        unit = nullptr;
        return;
    }
    unit = new BlackInfantryunit(unit1);
}

void BlackArmyFactory::createOppositeTowerunit(Towerunit *&unit, Towerunit *&unit1) {
    if (unit1 == nullptr) {
        std::cout << "You are trying to create unit from emptiness" << std::endl;
        unit = nullptr;
        return;
    }
    unit = new BlackTowerunit(unit1);
}

void BlackArmyFactory::createOppositeTankunit(Tankunit *&unit, Tankunit *&unit1) {
    if (unit1 == nullptr) {
        std::cout << "You are trying to create unit from emptiness" << std::endl;
        unit = nullptr;
        return;
    }
    unit = new BlackTankunit(unit1);
}