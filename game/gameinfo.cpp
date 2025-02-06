#include <iostream>
#include <cstdlib> // For system() function

int main() {
    std::string filename = "text.txt"; // Change this to your file name
    
    // Open the file using the system's default text editor
    std::string command = "start " + filename; // For Windows
    // std::string command = "xdg-open " + filename; // For Linux
    // std::string command = "open " + filename; // For macOS

    int result = system(command.c_str());
    
    if (result != 0) {
        std::cerr << "Error opening file! Make sure it exists." << std::endl;
    }
    
    return 0;
}
