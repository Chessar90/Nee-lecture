#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

struct Candidate {
    string name;
    int votes = 0;
};

struct Voter {
    string id;
    bool hasVoted = false;
};

class VotingSystem {
private:
    vector<Candidate> candidates;
    map<string, Voter> voters;
    bool votingOpen = false;

    Candidate* findCandidate(const string& name) {
        for (auto& candidate : candidates) {
            if (candidate.name == name) {
                return &candidate;
            }
        }
        return nullptr;
    }

public:
    void addCandidate(const string& name) {
        for (const auto& candidate : candidates) {
            if (candidate.name == name) {
                cout << "Error: Candidate '" << name << "' already exists!" << endl;
                return;
            }
        }
        candidates.push_back({name, 0});
        cout << "Candidate '" << name << "' added successfully." << endl;
    }

    void registerVoter(const string& voterId) {
        if (voters.find(voterId) != voters.end()) {
            cout << "Error: Voter '" << voterId << "' is already registered!" << endl;
            return;
        }
        voters[voterId] = {voterId, false};
        cout << "Voter with ID '" << voterId << "' registered successfully." << endl;
    }

    void openVoting() {
        if (votingOpen) {
            cout << "Error: Voting is already open!" << endl;
            return;
        }
        if (candidates.empty()) {
            cout << "Error: No candidates available. Add candidates first!" << endl;
            return;
        }
        votingOpen = true;
        cout << "Voting is now open!" << endl;
    }

    void closeVoting() {
        if (!votingOpen) {
            cout << "Error: Voting is not open!" << endl;
            return;
        }
        votingOpen = false;
        cout << "Voting is now closed!" << endl;
    }

    void castVote(const string& voterId, const string& candidateName) {
        if (!votingOpen) {
            cout << "Error: Voting is not open!" << endl;
            return;
        }
        if (voters.find(voterId) == voters.end()) {
            cout << "Error: Voter '" << voterId << "' is not registered!" << endl;
            return;
        }
        if (voters[voterId].hasVoted) {
            cout << "Error: Voter '" << voterId << "' has already voted!" << endl;
            return;
        }
        Candidate* candidate = findCandidate(candidateName);
        if (!candidate) {
            cout << "Error: Candidate '" << candidateName << "' not found!" << endl;
            return;
        }

        // Cast the vote
        candidate->votes++;
        voters[voterId].hasVoted = true;
        cout << "Vote successfully cast for '" << candidateName << "' by voter '" << voterId << "'." << endl;
    }

    void displayResults() const {
        if (votingOpen) {
            cout << "Warning: Voting is still open. Results may change!" << endl;
        }
        cout << "Election Results:" << endl;
        for (const auto& candidate : candidates) {
            cout << candidate.name << ": " << candidate.votes << " votes" << endl;
        }
    }

    void announceWinner() const {
        if (candidates.empty()) {
            cout << "No candidates available!" << endl;
            return;
        }
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
};

void displayMenu() {
    cout << "\n--- Secure Voting System ---" << endl;
    cout << "1. Add Candidate" << endl;
    cout << "2. Register Voter" << endl;
    cout << "3. Open Voting" << endl;
    cout << "4. Cast Vote" << endl;
    cout << "5. Close Voting" << endl;
    cout << "6. Display Results" << endl;
    cout << "7. Announce Winner" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    VotingSystem votingSystem;
    int choice;

    while (true) {
        displayMenu();
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
        case 1: {
            string candidateName;
            cout << "Enter candidate name: ";
            getline(cin, candidateName);
            votingSystem.addCandidate(candidateName);
            break;
        }
        case 2: {
            string voterId;
            cout << "Enter voter ID: ";
            getline(cin, voterId);
            votingSystem.registerVoter(voterId);
            break;
        }
        case 3:
            votingSystem.openVoting();
            break;
        case 4: {
            string voterId, candidateName;
            cout << "Enter voter ID: ";
            getline(cin, voterId);
            cout << "Enter candidate name: ";
            getline(cin, candidateName);
            votingSystem.castVote(voterId, candidateName);
            break;
        }
        case 5:
            votingSystem.closeVoting();
            break;
        case 6:
            votingSystem.displayResults();
            break;
        case 7:
            votingSystem.announceWinner();
            break;
        case 8:
            cout << "Exiting the system. Goodbye!" << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}