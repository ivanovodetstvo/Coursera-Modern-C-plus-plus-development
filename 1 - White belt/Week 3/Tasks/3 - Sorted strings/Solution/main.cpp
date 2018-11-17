class SortedStrings {
public:
    void AddString(const string& s) {
        strings.push_back(s);
    }

    vector < string > GetSortedStrings() {
        sort(strings.begin(), strings.end());
        return strings;
    }

private:
    vector < string > strings;
};
