void castVote(const string& voterId, const string& candidateName) {
    if (!votingOpen) {
        cout << "Error: Voting is not open!" << endl;
        return;
    }

    if (voters.find(voterId) == voters.end()) {
        cout << "Error: Voter " << voterId << " is not registered!" << endl;
        return;
    }

    if (voters[voterId].hasVoted) {
        cout << "Error: Voter " << voterId << " has already voted!" << endl;
        return;
    }

    Candidate* candidate = findCandidate(candidateName);
    if (!candidate) {
        cout << "Error: Candidate " << candidateName << " does not exist!" << endl;
        return;
    }

    // Casting the vote
    candidate->votes++;
    voters[voterId].hasVoted = true;
    cout << "Vote successfully cast for " << candidateName << " by voter " << voterId << "." << endl;
}