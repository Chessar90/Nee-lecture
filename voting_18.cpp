void handleNoCandidatesOrVoters() {
    if (candidates.empty()) {
        cout << "No candidates available. Add candidates first!" << endl;
    }
    if (voters.empty()) {
        cout << "No voters registered. Register voters first!" << endl;
    }
}