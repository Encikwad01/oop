#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct User {
    string name;
    string instagram;
    string handphoneNumber;
    string team;
};

bool isteamTaken(const vector<User>& users, const string& team) {
    for (const auto& u : users) {
        if (u.team == team) {
            return true;
        }
    }
    return false;
}

void displayInfo(const User& user) {
    cout << "Name: " << user.name << endl;
    cout << "Instagram: " << user.instagram << endl;
    cout << "Handphone Number: " << user.handphoneNumber << endl;
    cout << "Team: " << user.team << endl;
}


bool isDuplicateUser(const vector<User>& users, const string& name, const string& instagram) {
    for (const auto& u : users) {
        if ((name.empty() ? false : u.name == name) ||
            (instagram.empty() ? false : u.instagram == instagram)) {
            return true;
        }
    }
    return false;
}


int main() {
    vector<User> users;
    string confirmation;
    int count = 0;

    while (count < 2) {
        User user;
        
        cout << "Enter your Name: ";
        getline(cin, user.name);

        if (isDuplicateUser(users, user.name, "")) {
            cout << "Duplicate Name found. Please enter different information." << endl;
            continue;
        }

        cout << "Enter your Instagram: ";
        getline(cin, user.instagram);

        if (isDuplicateUser(users, "", user.instagram)) {
            cout << "Duplicate Instagram found. Please enter different information." << endl;
            continue;
        }

        cout << "Enter your Handphone Number: ";
        getline(cin, user.handphoneNumber);


        displayInfo(user);

        cout << "Is the above information correct? (Y/N): ";
        getline(cin, confirmation);

        if (confirmation == "N" || confirmation == "n") {
            cout << "Please run the program again to correct the information." << endl;
            continue;
        }

        bool confirmed = false;
        while (!confirmed) {
            cout << "Choose your team (A,B) [A/B]: ";
            getline(cin, user.team);

            if (user.team == "A" || user.team == "a") user.team = "A";
            else if (user.team == "B" || user.team == "b") user.team = "B";
            else {
                cout << "Please choose a valid option." << endl;
                continue;
            }

            if (isteamTaken(users, user.team)) {
                cout << "The team is already taken. Please choose a different team." << endl;
                continue;
            }

            cout << user.name << ", " << user.instagram << endl;
            cout << user.handphoneNumber << endl;
            cout << "You have selected " << user.team << ", Confirm Team? (Y/N): ";
            getline(cin, confirmation);

            if (confirmation == "Y" || confirmation == "y") {
                confirmed = true;
            }
        }

        users.push_back(user);

        cout << endl << "Users registered so far:" << endl;
        for (const auto& u : users) {
            displayInfo(u);
            cout << "-------------------" << endl;
        }

        count++;

        if (count < 2) {
            cout << "You can add " << (2 - count) << " more users." << endl;
        } else {
            cout << "Maximum number of users registered. Proceeding to the game." << endl;
        }
    }

    return 0;
}
