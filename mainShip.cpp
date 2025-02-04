#include "MoveShip.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>

int main() {
    srand(time(0));

    Battlefield battlefield(10, 10);

    battlefield.setIsland(1, 7); battlefield.setIsland(1, 8);
    battlefield.setIsland(2, 7); battlefield.setIsland(2, 8);
    battlefield.setIsland(4, 4); battlefield.setIsland(5, 4);
    battlefield.setIsland(6, 4); battlefield.setIsland(8, 5);
    battlefield.setIsland(8, 6); battlefield.setIsland(8, 7);
    battlefield.setIsland(9, 7);

    battlefield.placeShips('*', 5, 1);
    battlefield.placeShips('$', 4, 1);
    battlefield.placeShips('#', 4, 1);
    battlefield.placeShips('@', 3, 1);
    battlefield.placeShips('>', 2, 2);
    battlefield.placeShips('<', 3, 2);

    std::cout << "Initial Battlefield:\n";
    battlefield.displayBattlefield();

    battlefield.simulate(5); // to simulate iterations
    return 0;
}