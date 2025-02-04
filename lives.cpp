#include <iostream>
#include <queue>
#include <vector>
#include <memory>  // For smart pointers
#include <cstdlib> // For rand()
#include <ctime>

class Ship;  // Forward declaration (note: capital S)

class Battlefield {
private:
    int width, height;
    std::vector<std::vector<char>> grid;
    std::queue<std::shared_ptr<Ship>> reEntryQueue;  // Changed ship to Ship
    std::vector<std::shared_ptr<Ship>> ships;        // Changed ship to Ship

public:
    Battlefield(int width, int height)
        : width(width), height(height), grid(height, std::vector<char>(width, '.')) {
        srand(static_cast<unsigned int>(time(0)));
    }

    bool isEmpty(int x, int y) {
        return grid[y][x] == '.';
    }

    void addShip(std::shared_ptr<Ship> ship) {  // Changed Ship to ship (parameter name)
        grid[ship->getYPosition()][ship->getXPosition()] = ship->getSymbol();  // Changed Ship to ship
        ships.push_back(ship);  // Changed Ship to ship
    }

    void clearBattlefield() {
        for (auto& row : grid) {
            std::fill(row.begin(), row.end(), '.');
        }
    }

    void displayBattlefield() const {
        for (const auto& row : grid) {
            for (char cell : row) {
                std::cout << cell << ' ';
            }
            std::cout << '\n';
        }
    }

    void reEnterShips() {
        int count = 0;
        while (!reEntryQueue.empty() && count < 2) {
            auto ship = reEntryQueue.front();
            reEntryQueue.pop();

            int x, y;
            do {
                x = rand() % width;
                y = rand() % height;
            } while (!isEmpty(x, y));

            ship->setPosition(x, y);
            ship->restoreLives();
            addShip(ship);
            count++;
        }
    }

    void simulate(int iterations) {
        for (int i = 0; i < iterations; ++i) {
            std::cout << "\nIteration " << i + 1 << ":\n";
            clearBattlefield();
            reEnterShips();
            displayBattlefield();
        }
    }

    void queueShipForReEntry(std::shared_ptr<Ship> ship) {  // Changed Ship to ship (parameter name)
        reEntryQueue.push(ship);
    }
};

class Ship {  // Changed ship to Ship
protected:
    int lives;
    const int maxLives = 3;
    std::string type;
    int xPosition, yPosition;
    int team;
    char symbol;

public:
    Ship(std::string type, int xPosition, int yPosition, int team, char symbol)
        : type(type), xPosition(xPosition), yPosition(yPosition),
          lives(maxLives), team(team), symbol(symbol) {}

    virtual ~Ship() = default;

    virtual void move(Battlefield& battlefield) = 0;

    void takeDamage() {
        if (lives > 0) {
            lives--;
        }
    }

    bool isAlive() const { return lives > 0; }

    void restoreLives() { lives = maxLives; }

    int getXPosition() const { return xPosition; }
    int getYPosition() const { return yPosition; }
    char getSymbol() const { return symbol; }

    void setPosition(int x, int y) {
        xPosition = x;
        yPosition = y;
    }
};

class SimpleShip : public Ship {
public:
    SimpleShip(std::string type, int x, int y, int team, char symbol)
        : Ship(type, x, y, team, symbol) {}

    void move(Battlefield& battlefield) override {
        // Example movement logic (do nothing)
        std::cout << type << " at (" << getXPosition() << ", " << getYPosition() << ") moves.\n";
    }
};

int main() {
    Battlefield battlefield(10, 10);

    // Create ships and add them to the battlefield
    auto ship1 = std::make_shared<SimpleShip>("Cruiser", 2, 3, 1, 'C');
    auto ship2 = std::make_shared<SimpleShip>("Destroyer", 5, 7, 1, 'D');

    battlefield.addShip(ship1);
    battlefield.addShip(ship2);

    std::cout << "Initial Battlefield:\n";
    battlefield.displayBattlefield();

    // Queue ships for re-entry
    battlefield.queueShipForReEntry(ship1);
    battlefield.queueShipForReEntry(ship2);

    // Simulate battlefield iterations
    battlefield.simulate(5);

    return 0;
}
