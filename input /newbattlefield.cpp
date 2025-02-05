#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Battlefield {
    private:
        vector<vector<int>> battlefield;
        int width, height;
        int iterations;
        struct Ship {
            string name;
            char symbol;
            int size;
        };
        vector<Ship> teamA;
        vector<Ship> teamB;

    public:
        Battlefield(const string& filename) {
            loadConfig(filename);
            battlefield.resize(height, vector<int>(width, 0));
        }

        void loadConfig(const string& filename) {
            ifstream file(filename);
            string line;
            
            // Read iterations
            file >> line >> iterations;
            
            // Read width and height
            file >> line >> width;
            file >> line >> height;
            
            // Read Team A configuration
            int teamASize;
            file >> line >> line >> teamASize;  // "Team" "A" <size>
            
            for (int i = 0; i < teamASize; i++) {
                Ship ship;
                file >> ship.name >> ship.symbol >> ship.size;
                teamA.push_back(ship);
            }
            
            // Read Team B configuration
            int teamBSize;
            file >> line >> line >> teamBSize;  // "Team" "B" <size>
            
            for (int i = 0; i < teamBSize; i++) {
                Ship ship;
                file >> ship.name >> ship.symbol >> ship.size;
                teamB.push_back(ship);
            }
            
            file.close();
        }

        void setIsland(int x, int y, int value) {
            if (x >= 0 && x < width && y >= 0 && y < height) {
                battlefield[y][x] = value;
            } else {
                cout << "The position (" << x << "," << y << ") is invalid" << endl;
            }
        }

        void displayBattlefield() const {
            for (const auto& row : battlefield) {
                for (int island : row) {
                    cout << island << " ";
                }
                cout << endl;
            }
        }

        void displayConfig() const {
            cout << "Configuration:" << endl;
            cout << "Iterations: " << iterations << endl;
            cout << "Width: " << width << endl;
            cout << "Height: " << height << endl;
            
            cout << "\nTeam A Ships:" << endl;
            for (const auto& ship : teamA) {
                cout << ship.name << " " << ship.symbol << " " << ship.size << endl;
            }
            
            cout << "\nTeam B Ships:" << endl;
            for (const auto& ship : teamB) {
                cout << ship.name << " " << ship.symbol << " " << ship.size << endl;
            }
        }
};

int main() {
    // Create battlefield using config file
    Battlefield battlefield("text.txt");
    
    // Display loaded configuration
    battlefield.displayConfig();
    
    // Set specific cells to 1 as per the pattern
    battlefield.setIsland(1, 7, 1);
    battlefield.setIsland(1, 8, 1);
    battlefield.setIsland(2, 7, 1);
    battlefield.setIsland(2, 8, 1);
    
    battlefield.setIsland(4, 4, 1);
    battlefield.setIsland(5, 4, 1);
    battlefield.setIsland(6, 4, 1);
    
    battlefield.setIsland(8, 5, 1);
    battlefield.setIsland(8, 6, 1);
    battlefield.setIsland(8, 7, 1);
    battlefield.setIsland(9, 7, 1);
    
    // Display the grid
    battlefield.displayBattlefield();
    
    return 0;
}
