#ifndef MOVESHIP_H
#define MOVESHIP_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <memory> // For shared_ptr
#include <map>

class Battlefield; // Forward declaration

// Base class
class Ship {
protected:
    std::string name;
    int x, y;
    int lives;
    int team;
    char symbol;
    int kills = 0;

public:
    Ship(std::string name, int x, int y, int team, char symbol);
    virtual ~Ship() {}

    virtual void look() = 0;
    virtual void move() = 0;
    virtual void shoot(int targetX, int targetY) = 0;
    virtual void ram() = 0;
    virtual void performActions(Battlefield& battlefield) = 0;

    std::string getName() const;
    int getX() const;
    int getY() const;
    int getLives() const;
    int getTeam() const;
    char getSymbol() const;

    void takeDamage();
    void setPosition(int newX, int newY);
    bool isAlive() const { return lives > 0; }
};

// Derived classes
class MovingShip : virtual public Ship {
public:
    MovingShip(std::string name, int x, int y, int team, char symbol);
    void move() override;
};

class ShootingShip : virtual public Ship {
public:
    ShootingShip(std::string name, int x, int y, int team, char symbol);
    void shoot(int targetX, int targetY) override;
};

class SeeingShip : virtual public Ship {
public:
    SeeingShip(std::string name, int x, int y, int team, char symbol);
    void look() override;
};

class RamShip : virtual public Ship {
public:
    RamShip(std::string name, int x, int y, int team, char symbol);
    void ram() override;
};

// Specific Ship Implementations
class Battleship : public MovingShip, public ShootingShip, public SeeingShip {
public:
    Battleship(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

class Cruiser : public MovingShip, public RamShip, public SeeingShip {
public:
    Cruiser(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

class Destroyer : public MovingShip, public ShootingShip, public RamShip, public SeeingShip {
public:
    Destroyer(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

class Frigate : public ShootingShip {
private:
    int fireDirection; // Track the current fire direction

public:
    Frigate(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

class Corvette : public ShootingShip {
public:
    Corvette(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

class Amphibious : public MovingShip, public ShootingShip {
public:
    Amphibious(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

class SuperShip : public MovingShip, public ShootingShip, public RamShip {
public:
    SuperShip(std::string name, int x, int y, int team, char symbol);
    void performActions(Battlefield& battlefield) override;
};

// Battlefield class
class Battlefield {
private:
    std::vector<std::vector<char>> battlefield;
    int width, height;
    std::map<int, std::shared_ptr<Ship>> ships; // Store ships as shared_ptr
    int shipCounter = 0; // Unique ID counter

public:
    Battlefield(int width, int height);
    void setIsland(int x, int y);
    bool isValidPosition(int x, int y);
    bool isEmpty(int x, int y);
    std::shared_ptr<Ship> createShip(char symbol, int x, int y, int team);
    void placeShips(char symbol, int count, int team);
    void displayBattlefield() const;
    void simulate(int iterations);
    void addShip(std::shared_ptr<Ship> ship);
};

#endif
