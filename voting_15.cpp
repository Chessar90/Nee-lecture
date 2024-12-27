void displayRealTimeVotes() const {
    cout << "Real-Time Voting Progress:" << endl;
    for (const auto& candidate : candidates) {
        cout << candidate.name << ": " << candidate.votes << " votes" << endl;
    }
}