void castVote(Poll &p, bool vote) {
    if (vote) p.yesVotes++;
    else p.noVotes++;
}