void createPoll(Poll &p) {
    cout << "Enter Poll ID: ";
    cin >> p.id;
    cout << "Enter Poll Question: ";
    cin.ignore();
    getline(cin, p.question);
    p.yesVotes = p.noVotes = 0;
}