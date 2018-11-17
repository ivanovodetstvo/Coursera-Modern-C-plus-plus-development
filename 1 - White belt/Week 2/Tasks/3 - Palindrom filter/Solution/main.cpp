bool IsPalindrom(string s) {
    string s1 = s;
    for (size_t i = 0; i < s.length(); i++)
        s1[i] = s[s.length() - 1 - i];
	return s == s1;
}

 vector < string > PalindromFilter(const vector < string > &words, const int &minLength) {
     vector < string > ans;
     ans.clear();
     for (auto word : words) {
        if (word.length() >= minLength && IsPalindrom(word))
            ans.push_back(word);
     }
    return ans;
 }
