void showMenu() {
    cout << "1. Add Candidate\n2. Register Voter\n3. Open Voting\n4. Cast Vote\n";
    cout << "5. Close Voting\n6. Display Results\n7. Announce Winner\n8. Save Data\n";
    cout << "9. Load Data\n10. Exit\n";
}

void handleMenuOption(int option) {
    switch (option) {
        case 1: // Add candidate
            break;
        case 2: // Register voter
            break;
        case 3: // Open voting
            break;
        case 4: // Cast vote
            break;
        case 5: // Close voting
            break;
        case 6: // Display results
            break;
        case 7: // Announce winner
            break;
        case 8: // Save data
            break;
        case 9: // Load data
            break;
        case 10:
            cout << "Exiting system." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
    }
}