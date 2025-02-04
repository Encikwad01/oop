#include "MoveShip.h"
#include <iostream>
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random numbers

// Constructor for Ship
Ship::Ship(std::string name, int x, int y, int team, char symbol)
    : name(name), x(x), y(y), lives(3), team(team), symbol(symbol) {}

// Getters
std::string Ship::getName() const { return name; }
int Ship::getX() const { return x; }
int Ship::getY() const { return y; }
int Ship::getLives() const { return lives; }
int Ship::getTeam() const { return team; }
char Ship::getSymbol() const { return symbol; }

// Take damage
void Ship::takeDamage() { lives--; }

// Update position
void Ship::setPosition(int newX, int newY)
{
    x = newX;
    y = newY;
}

// Constructor for MovingShip
MovingShip::MovingShip(std::string name, int x, int y, int team, char symbol)
    : Ship(name, x, y, team, symbol) {}

void MovingShip::move()
{
    int direction = rand() % 4;
    switch (direction)
    {
    case 0:
        y--;
        break;
    case 1:
        y++;
        break;
    case 2:
        x--;
        break;
    case 3:
        x++;
        break;
    }
    std::cout << name << " moved to (" << x << ", " << y << ")\n";
}

// Constructor for ShootingShip
ShootingShip::ShootingShip(std::string name, int x, int y, int team, char symbol)
    : Ship(name, x, y, team, symbol) {}

void ShootingShip::shoot(int targetX, int targetY)
{
    if (targetX == x && targetY == y)
        return; // Prevent shooting at itself
    std::cout << name << " shoots at (" << targetX << ", " << targetY << ")\n";
}

// Constructor for SeeingShip
SeeingShip::SeeingShip(std::string name, int x, int y, int team, char symbol)
    : Ship(name, x, y, team, symbol) {}

void SeeingShip::look()
{
    std::cout << name << " looks around at (" << x << ", " << y << ")\n";
}

// Constructor for RamShip
RamShip::RamShip(std::string name, int x, int y, int team, char symbol)
    : Ship(name, x, y, team, symbol) {}

void RamShip::ram()
{
    std::cout << name << " destroys enemy at (" << x << ", " << y << ")\n";
}

// Implement all ship types
void Battleship::performActions(Battlefield& battlefield)
{
    look();
    move();

    for (int i = 0; i < 2; i++)
    {
        int dx = (rand() % 11) - 5;
        int dy = (rand() % (6 - abs(dx))) * ((rand() % 2) ? 1 : -1);
        shoot(x + dx, y + dy);
    }

    if (kills >= 4)
    {
        std::cout << "Battleship upgraded to Destroyer!\n";
        auto newShip = std::make_shared<Destroyer>(name, x, y, team, symbol);
        battlefield.addShip(newShip);
    }
}

void Cruiser::performActions(Battlefield& battlefield)
{
    look();
    move();
    ram();

    if (kills >= 3)
    {
        std::cout << "Cruiser upgraded to Destroyer!\n";
        auto newShip = std::make_shared<Destroyer>(name, x, y, team, symbol);
        battlefield.addShip(newShip);
    }
}

void Destroyer::performActions(Battlefield& battlefield)
{
    look();
    move();
    shoot(x + (rand() % 3 - 1), y + (rand() % 3 - 1));
    ram();

    if (kills >= 3)
    {
        std::cout << "Destroyer upgraded to SuperShip!\n";
        auto newShip = std::make_shared<SuperShip>(name, x, y, team, symbol);
        battlefield.addShip(newShip);
    }
}

void Frigate::performActions(Battlefield& battlefield)
{
    static int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
    static int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

    shoot(x + dx[fireDirection], y + dy[fireDirection]);
    fireDirection = (fireDirection + 1) % 8;

    if (kills >= 3)
    {
        std::cout << "Frigate upgraded to Corvette!\n";
        auto newShip = std::make_shared<Corvette>(name, x, y, team, symbol);
        battlefield.addShip(newShip);
    }
}

void Corvette::performActions(Battlefield& battlefield)
{
    int dx = (rand() % 3) - 1;
    int dy = (rand() % 3) - 1;
    if (dx != 0 || dy != 0)
    {
        shoot(x + dx, y + dy);
    }
}

void Amphibious::performActions(Battlefield& battlefield)
{
    look();
    move();
    shoot(x + (rand() % 3 - 1), y + (rand() % 3 - 1));
    shoot(x + (rand() % 3 - 1), y + (rand() % 3 - 1));

    if (kills >= 4)
    {
        std::cout << "Amphibious upgraded to SuperShip!\n";
        auto newShip = std::make_shared<SuperShip>(name, x, y, team, symbol);
        battlefield.addShip(newShip);
    }
}

void SuperShip::performActions(Battlefield& battlefield)
{
    move();
    shoot(x + (rand() % 3 - 1), y + (rand() % 3 - 1));
    shoot(x + (rand() % 3 - 1), y + (rand() % 3 - 1));
    shoot(x + (rand() % 3 - 1), y + (rand() % 3 - 1));
}

void Battlefield::addShip(std::shared_ptr<Ship> ship)
{
    ships[shipCounter++] = ship;
}

// Implementation of other methods like `placeShips`, `simulate`, etc.
