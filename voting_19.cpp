bool isValidName(const string& name) {
    return !name.empty() && isalpha(name[0]);
}