map<string, string> voterPasswords; // Map of voter ID to password

void registerVoterWithPassword(const string& voterId, const string& password) {
    if (voters.find(voterId) == voters.end()) {
        voters[voterId] = {voterId, false};
        voterPasswords[voterId] = password;
        cout << "Voter " << voterId << " registered with a password." << endl;
    } else {
        cout << "Voter " << voterId << " is already registered!" << endl;
    }
}

bool authenticateVoter(const string& voterId, const string& password) {
    if (voterPasswords[voterId] == password) {
        return true;
    }
    cout << "Authentication failed for voter " << voterId << endl;
    return false;
}