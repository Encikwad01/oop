#include <iostream>
#include <vector>
using namespace std;

class Battlefield{
    private:
    vector<vector<int>> battlefield;
    int width,height;

    public:
    Battlefield(int width,int height):width(width),height(height){
        battlefield.resize(width, vector<int>(height, 0));
    }

    void setIsland(int x, int y, int value) {
        if (x >= 0 && x < width && y >= 0 && y < height) {
            battlefield[x][y] = value;
        } else {
           cout<<"The position of the("<<x<<","<<y<<")is invalid"<<endl;
        }
    }

     void displaybattlefield() const {
        for (const auto& width : battlefield) {
            for (int island : width) {
                cout << island << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Battlefield battlefield(10, 10); // Create a 10x10 grid

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
    battlefield.displaybattlefield();

    return 0;
}