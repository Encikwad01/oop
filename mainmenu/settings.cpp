#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to display settings from text.txt
void displaySettings() {
    ifstream file("text.txt"); // Open text file
    if (!file) {
        cout << "Error: text.txt not found!\n";
        return;
    }

    cout << "\n⚙️  Warship Configuration Settings ⚙️\n";
    string line;
    while (getline(file, line)) { // Read file line by line
        cout << line << endl;
    }
    file.close();
}

// Function to modify settings (Open text.txt for editing)
void modifySettings() {
    cout << "\nOpening text.txt for modification...\n";
    system("notepad text.txt"); // Opens the file in Notepad (Windows)
}

// Function to handle settings menu
void settingsMenu() {
    int option;
    while (true) {
        cout << "\n ----------------------------------- \n";
        cout << "|          ⚙️ SETTINGS MENU          |\n";
        cout << " ----------------------------------- \n";
        cout << "| 1. Modify Settings                 |\n";
        cout << "| 2. Go Back to Main Menu            |\n";
        cout << " ----------------------------------- \n";
        cout << "Select an option: ";
        cin >> option;

        switch (option) {
            case 1:
                modifySettings();
                break;
            case 2:
                return; // Go back to main menu
            default:
                cout << "\n❌ Invalid option. Try again.\n";
        }
    }
}
