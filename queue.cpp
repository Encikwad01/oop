#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

class Ship {
protected:
   std::string symbol;
   std::string type;
   int size;
   bool destroyed;

public:
   Ship(std::string sym, std::string shiptype, int sz) :
      symbol(sym), type(shiptype), size(sz), destroyed(false) {}

   virtual std::string getSymbol() const { return symbol; }
   virtual std::string getType() const { return type; }
   virtual int getSize() const { return size; }
   virtual bool isShipDestroyed() const { return destroyed; }
   virtual void markShipDestroyed() { destroyed = true; }
};

class Team {
private:
    std::string shipname;
    std::queue<Ship*> ships;

public:
    Team(std::string name) : shipname(name) {}

    void addShip(Ship* ship) {
        ships.push(ship);
    }

    Ship* getCurrentShip() {
        if (ships.empty()) return nullptr;
        return ships.front();
    }

    void removeCurrentShip() {
        if (!ships.empty()) {
            delete ships.front();
            ships.pop();
        }
    }

    bool hasRemainingShips() const {
        return !ships.empty();
    }

    std::string getName() const {
        return shipname;
    }

    int getRemainingShipCount() const {
        return ships.size();
    }
};

class TeamABattleship : public Ship {
public:
    TeamABattleship(std::string symbol) : Ship(symbol, "Battleship", 5) {}
};

class TeamACruiser : public Ship {
public:
    TeamACruiser(std::string symbol) : Ship(symbol, "Cruiser", 4) {}
};

class TeamADestroyer : public Ship {
public:
    TeamADestroyer(std::string symbol) : Ship(symbol, "Destroyer", 4) {}
};

class TeamAFrigate : public Ship {
public:
    TeamAFrigate(std::string symbol) : Ship(symbol, "Frigate", 3) {}
};

class TeamBBattleship : public Ship {
public:
    TeamBBattleship(std::string symbol) : Ship(symbol, "Battleship", 2) {}
};

class TeamBCruiser : public Ship {
public:
     TeamBCruiser(std::string symbol) : Ship(symbol, "Cruiser", 3) {}
};

class Warshipgame {
private:
    Team teamA;
    Team teamB;

public:
    Warshipgame() : teamA("TEAM A"), teamB("TEAM B") {
        initializeTeamA();
        initializeTeamB();
    }

    void initializeTeamA() {
        teamA.addShip(new TeamABattleship("*1"));
        teamA.addShip(new TeamABattleship("*2"));
        teamA.addShip(new TeamABattleship("*3"));
        teamA.addShip(new TeamABattleship("*4"));
        teamA.addShip(new TeamABattleship("*5"));

        teamA.addShip(new TeamACruiser("$1"));
        teamA.addShip(new TeamACruiser("$2"));
        teamA.addShip(new TeamACruiser("$3"));
        teamA.addShip(new TeamACruiser("$4"));

        teamA.addShip(new TeamADestroyer("#1"));
        teamA.addShip(new TeamADestroyer("#2"));
        teamA.addShip(new TeamADestroyer("#3"));
        teamA.addShip(new TeamADestroyer("#4"));

        teamA.addShip(new TeamAFrigate("@1"));
        teamA.addShip(new TeamAFrigate("@2"));
        teamA.addShip(new TeamAFrigate("@3"));
    }

    void initializeTeamB() {
        teamB.addShip(new TeamBBattleship(">1"));
        teamB.addShip(new TeamBBattleship(">2"));

        teamB.addShip(new TeamBCruiser("<1"));
        teamB.addShip(new TeamBCruiser("<2"));
        teamB.addShip(new TeamBCruiser("<3"));
    }

    void displayGameStatus() {
        std::cout << "Team A Remaining Ships: " << teamA.getRemainingShipCount() << std::endl;
        std::cout << "Team B Remaining Ships: " << teamB.getRemainingShipCount() << std::endl;
    }

    ~Warshipgame() {
        while (teamA.hasRemainingShips()) {
            teamA.removeCurrentShip();
        }
        while (teamB.hasRemainingShips()) {
            teamB.removeCurrentShip();
        }
    }
};

int main() {
    Warshipgame game;
    game.displayGameStatus();
    return 0;
}
