void MoveStrings(vector < string > &source, vector < string > &destination) {
    for (auto str : source)
        destination.push_back(str);

    source.clear();

    return;
}
