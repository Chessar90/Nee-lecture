#include <fstream>

void saveToFile() {
    ofstream file("voting_data.txt");
    if (file.is_open()) {
        for (const auto& candidate : candidates) {
            file << "C " << candidate.name << " " << candidate.votes << endl;
        }
        for (const auto& [id, voter] : voters) {
            file << "V " << voter.id << " " << voter.hasVoted << endl;
        }
        file.close();
        cout << "Data saved successfully." << endl;
    }
}

void loadFromFile() {
    ifstream file("voting_data.txt");
    if (file.is_open()) {
        string type;
        while (file >> type) {
            if (type == "C") {
                string name;
                int votes;
                file >> name >> votes;
                candidates.push_back({name, votes});
            } else if (type == "V") {
                string id;
                bool hasVoted;
                file >> id >> hasVoted;
                voters[id] = {id, hasVoted};
            }
        }
        file.close();
        cout << "Data loaded successfully." << endl;
    }
}