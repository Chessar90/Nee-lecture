#include <random> // Include for random number generation

string generateUniqueID() {
    static int counter = 1;
    return "Voter" + to_string(counter++);
}

void registerVoterAuto() {
    string voterId = generateUniqueID();
    if (voters.find(voterId) == voters.end()) {
        voters[voterId] = {voterId, false};
        cout << "Voter " << voterId << " registered automatically." << endl;
    }
}