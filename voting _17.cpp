Candidate* findCandidate(const string& name) {
    for (auto& candidate : candidates) {
        if (candidate.name == name) {
            return &candidate;
        }
    }
    return nullptr;
}