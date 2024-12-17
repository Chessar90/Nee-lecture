#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// User database storing username and password
unordered_map<string, string> userDatabase = {
    {"admin", "admin123"},
    {"voter1", "vote@123"},
    {"voter2", "password456"}
};

// Function to authenticate user
bool authenticateUser(const string &username, const string &password) {
    if (userDatabase.find(username) != userDatabase.end() && userDatabase[username] == password) {
        return true;
    }
    return false;
}

// Main function: Login logic for voting system
int main() {
    string username, password;
    int attempts = 3; // Allow 3 login attempts

    cout << "=== Voting System Login ===" << endl;

    while (attempts > 0) {
        cout << "Enter Username: ";
        cin >> username;

        cout << "Enter Password: ";
        cin >> password;

        // Authenticate user
        if (authenticateUser(username, password)) {
            cout << "\nLogin Successful! Welcome, " << username << "." << endl;
            if (username == "admin") {
                cout << "Access granted: Admin privileges." << endl;
            } else {
                cout << "Access granted: Voter privileges." << endl;
            }
            cout << "Proceeding to the voting system..." << endl;
            break;
        } else {
            attempts--;
            cout << "Invalid credentials! You have " << attempts << " attempt(s) left.\n" << endl;
        }

        if (attempts == 0) {
            cout << "Too many failed attempts. Exiting the system." << endl;
        }
    }

    return 0;
}