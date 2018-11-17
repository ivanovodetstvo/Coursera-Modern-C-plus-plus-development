vector < int > Reversed(const vector < int > &v) {
    vector < int > tmp;
    for (size_t i = 0; i < v.size(); i++)
        tmp.push_back(v[v.size() - 1 - i]);

    return tmp;
}

