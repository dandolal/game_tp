//
// Created by daniil on 27.03.19.
//

#include <iostream>


#ifndef GAME_WARIORS_H
#define GAME_WARIORS_H

class Unit {
public:
    Unit() {}

    Unit(int pos_x, int pos_y, int hp_, int force_, int speed_) : hp(hp_), force(force_), speed(speed_) {
        position.first = pos_x;
        position.second = pos_y;
    }

    virtual void info() = 0;

    virtual ~Unit() {}

    virtual void SetType(char type_);

    virtual char GetType();

    virtual std::pair<int, int> GetPosition();

    virtual int GetHP();

    virtual int GetForce();

    virtual int GetSpeed();

    virtual void SetSpeed(int speed_);

    virtual void SetHP(int hp_);

    virtual void ReduceHP(int deltahp);

    virtual void IncreaseHP(int deltahp);

    virtual void SetForce(int force_);

    virtual void SetPosition(std::pair<int, int> position_);

    virtual bool CheckAlive();

private:
    char type;
    std::pair<int, int> position;
    int hp;
    int force;
    int speed;
};

class Infantryunit : public Unit {
public:
    Infantryunit() : Unit(-1, -1, 100, 5, 2) {};

    virtual void info() = 0;

    virtual ~Infantryunit() {}
};

class Tankunit : public Unit {
public:
    Tankunit() : Unit(-1, -1, 500, 200, 5) {};

    virtual void info() = 0;

};

class Towerunit : public Unit {
public:
    Towerunit() : Unit(-1, -1, 1000, 800, 1) {};

    virtual void info() = 0;

    ~Towerunit() {}
};

class WhiteInfantryunit : public Infantryunit {
public:
    void info();

};

class WhiteTankunit : public Tankunit {
public:
    void info();
};

class WhiteTowerunit : public Towerunit {
public:
    void info();
};

class BlackInfantryunit : public Infantryunit {
public:
    BlackInfantryunit() {};

    BlackInfantryunit(Infantryunit *&unit);

    void info();
};

class BlackTankunit : public Tankunit {
public:
    BlackTankunit() {};

    BlackTankunit(Tankunit *&unit);

    void info();
};

class BlackTowerunit : public Towerunit {
public:
    BlackTowerunit() {};

    BlackTowerunit(Towerunit *&unit);

    void info();
};

#endif //GAME_WARIORS_H
