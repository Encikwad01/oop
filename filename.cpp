#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

class FileReader {
public:
    // Constructor to initialize with a file name
    FileReader(const string& fileName) : fileName(fileName) {}

    // Method to read and process file contents
    void processFile() {
        ifstream inputFile(fileName);

        // Check if the file opened successfully
        if (!inputFile) {
            cerr << "Error: Could not open the file " << fileName << endl;
            return;
        }

        string line;
        cout << "Processing file contents:" << endl;

        // Read the file line by line
        while (getline(inputFile, line)) {
            vector<int> values = parseLine(line);
            int result = multiplyValues(values);
            cout << "Line: " << line << " => Result: " << result << endl;
        }

        inputFile.close(); // Close the file
    }

private:
    string fileName; // Name of the file to read

    // Function to parse a line into integers
    vector<int> parseLine(const string& line) {
        vector<int> values;
        stringstream ss(line);
        int value;
        while (ss >> value) {
            values.push_back(value);
        }
        return values;
    }

    // Function to multiply values in a vector
    int multiplyValues(const vector<int>& values) {
        int result = 1;
        for (int value : values) {
            result *= value;
        }
        return result;
    }
};

int main() {
    string fileName = "text.txt"; // Replace with your file name
    FileReader fileReader(fileName);

    // Process the file contents
    fileReader.processFile();

    return 0;
}