bool IsPalindrom(string s) {
    string s1 = s;
    for (size_t i = 0; i < s.length(); i++)
        s1[i] = s[s.length() - 1 - i];
	return s == s1;
}
