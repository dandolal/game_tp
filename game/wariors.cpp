//
// Created by daniil on 28.03.19.
//
#include "wariors.h"
#include <iostream>

void Unit::SetType(char type_) {
    type = type_;
}

char Unit::GetType() {
    return type;
}

std::pair<int, int> Unit::GetPosition() { return position; }

int Unit::GetForce() { return force; }

int Unit::GetHP() { return hp; }

int Unit::GetSpeed() { return speed; }

void Unit::SetForce(int force_) { force = force_; }

void Unit::SetHP(int hp_) { hp = hp_; }

void Unit::SetPosition(std::pair<int, int> position_) { position = position_; }

void Unit::SetSpeed(int speed_) { speed = speed_; }

void Unit::ReduceHP(int deltahp) { hp -= deltahp; }

void Unit::IncreaseHP(int deltahp) { hp += deltahp; }

bool Unit::CheckAlive() { return hp > 0; }

void WhiteInfantryunit::info() {
    std::cout << "WhiteInfantryunit type: " << GetType() << " hp: " << GetHP() << " speed: " << GetSpeed() << " force: "
              << GetForce() << " pos_x: " << GetPosition().first << " pos_y: " << GetPosition().second << std::endl;
}

void WhiteTowerunit::info() {
    std::cout << "WhiteTowerunit type: " << GetType() << " hp: " << GetHP() << " speed: " << GetSpeed() << " force: "
              << GetForce() << " pos_x: " << GetPosition().first << " pos_y: " << GetPosition().second << std::endl;
}

void WhiteTankunit::info() {
    std::cout << "WhiteTankunit type: " << GetType() << " hp: " << GetHP() << " speed: " << GetSpeed() << " force: "
              << GetForce() << " pos_x: " << GetPosition().first << " pos_y: " << GetPosition().second << std::endl;
}

void BlackInfantryunit::info() {
    std::cout << "BlackInfantryunit type: " << GetType() << " hp: " << GetHP() << " speed: " << GetSpeed() << " force: "
              << GetForce() << " pos_x: " << GetPosition().first << " pos_y: " << GetPosition().second << std::endl;
}

void BlackTowerunit::info() {
    std::cout << "BlackTowerunit type: " << GetType() << " hp: " << GetHP() << " speed: " << GetSpeed() << " force: "
              << GetForce() << " pos_x: " << GetPosition().first << " pos_y: " << GetPosition().second << std::endl;
}

void BlackTankunit::info() {
    std::cout << "BlackTankunit type: " << GetType() << " hp: " << GetHP() << " speed: " << GetSpeed() << " force: "
              << GetForce() << " pos_x: " << GetPosition().first << " pos_y: " << GetPosition().second << std::endl;
}

BlackInfantryunit::BlackInfantryunit(Infantryunit *&unit) {
    SetSpeed(unit->GetSpeed());
    SetType('b');
    SetForce(unit->GetForce());
}

BlackTowerunit::BlackTowerunit(Towerunit *&unit) {
    SetSpeed(unit->GetSpeed());
    SetType('b');
    SetForce(unit->GetForce());
}

BlackTankunit::BlackTankunit(Tankunit *&unit) {
    SetSpeed(unit->GetSpeed());
    SetType('b');
    SetForce(unit->GetForce());
}