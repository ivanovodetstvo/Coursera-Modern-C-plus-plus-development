vector<int> Reversed(const vector<int>& input) {
    auto seq = input;
    for (int i = 0; i < seq.size() / 2; ++i) {
        auto tmp = seq[i];
        seq[i] = seq[seq.size() - 1 - i];
        seq[seq.size() - 1 - i] = tmp;
    }
    return seq;
}
