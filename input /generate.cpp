#include <iostream>
#include <fstream>
#include <random>
#include <sstream>

// Function to generate random integers within a range
int getRandomInt(int min, int max)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

int main()
{
    std::ofstream file("game.txt"); // Create or overwrite the game.txt file

    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open game.txt for writing." << std::endl;
        return 1;
    }

    int iterations = getRandomInt(10, 50);
    int width = getRandomInt(10, 25);
    int height = getRandomInt(10, 25);
    int teams = getRandomInt(2, 3);
    file << iterations << "\n";
    file << width << "\n";
    file << height << "\n";

    // Generate random team data
    for (int i = 1; i <= teams; ++i)
    {
        std::stringstream lineStream;
        lineStream << i << " ";
        int shipTypes = getRandomInt(1, 6);
        for (int j = 0; j < shipTypes; j++)
        {
            int shipType = getRandomInt(0, 6);
            int shipCount = getRandomInt(1, 3);
            lineStream << shipType << " " << shipCount << " ";
        }
        file << lineStream.str() << "\n";
    }

    file.close();

    std::cout << "Successfully generated game.txt" << std::endl;
    return 0;
}