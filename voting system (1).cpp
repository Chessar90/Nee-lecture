void displayResults() const {
    cout << "Election Results:" << endl;
    for (const auto& candidate : candidates) {
        cout << candidate.name << ": " << candidate.votes << " votes" << endl;
    }
}