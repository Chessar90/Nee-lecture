void registerVoter(const string& voterId) {
    if (voters.find(voterId) != voters.end()) {
        cout << "Error: Voter " << voterId << " is already registered!" << endl;
        return;
    }
    voters[voterId] = {voterId, false};
    cout << "Voter " << voterId << " registered successfully." << endl;
}