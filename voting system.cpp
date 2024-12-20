void announceWinner() const {
    int maxVotes = 0;
    vector<string> winners;
    for (const auto& candidate : candidates) {
        if (candidate.votes > maxVotes) {
            maxVotes = candidate.votes;
            winners = {candidate.name};
        } else if (candidate.votes == maxVotes) {
            winners.push_back(candidate.name);
        }
    }
    cout << "Winner(s): ";
    for (const auto& winner : winners) {
        cout << winner << " ";
    }
    cout << "with " << maxVotes << " votes." << endl;
}