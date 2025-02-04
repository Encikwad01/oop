#include <iostream>
#include <cstdlib> // For system("cls")
#include <unistd.h> // For sleep()
#include "settings.cpp" // Include settings file

using namespace std;

// Function to display the Warship Simulation Menu
void displayMenu() {
    cout << "  -----------------------------------  \n";
    cout << " |                                   | \n";
    cout << " |         WARSHIP SIMULATION        | \n";
    cout << " |                                   | \n";
    cout << "  -----------------------------------  \n";
    cout << " | 1. Start                          | \n";
    cout << " | 2. Settings                       | \n";
    cout << " | 3. Quit                           | \n";
    cout << "  -----------------------------------  \n";
    cout << " Select an option: ";
}

// Function to simulate starting the game
void startSimulation() {
    cout << "\nLoading Warship Simulation...\n";
    sleep(2); // Simulates loading time
    cout << "🚢 The battle begins! Prepare for war! 🚢\n\n";
}

int main() {
    int choice;

    while (true) {
        system("cls"); // Clear screen (Windows), use system("clear") for Linux/Mac
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                startSimulation();
                break;
            case 2:
                settingsMenu(); // Opens the settings menu
                break;
            case 3:
                cout << "\nExiting the program. Goodbye, Captain! ⚓\n";
                return 0;
            default:
                cout << "\n❌ Invalid option. Please try again.\n";
        }

        // Pause before refreshing the menu
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    return 0;
}
