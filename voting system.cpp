void castVote(const string& voterId, const string& candidateName) {
    if (!votingOpen) {
        cout << "Voting is not open yet!" << endl;
        return;
    }

    if (voters.find(voterId) == voters.end() || voters[voterId].hasVoted) {
        cout << "Voter is either not registered or has already voted!" << endl;
        return;
    }

    for (auto& candidate : candidates) {
        if (candidate.name == candidateName) {
            candidate.votes++;
            voters[voterId].hasVoted = true;
            cout << "Vote cast successfully for " << candidateName << endl;
            return;
        }
    }
    cout << "Candidate not found!" << endl;
}