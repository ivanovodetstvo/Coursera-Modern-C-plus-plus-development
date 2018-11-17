#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

bool cmp(const string &a, const string &b) {
    string new_a = a;
    string new_b = b;

    for (auto& ai: new_a) {
        ai = (char) tolower(ai);
    }
    for (auto& bi: new_b) {
        bi = (char) tolower(bi);
    }

    return new_a < new_b;
}

int main() {
//    freopen("INPUT.TXT", "r+", stdin);
//    freopen("OUTPUT.TXT", "w+", stdout);

    int n;
    cin >> n;
    vector < string > words(n);
    for (auto& word: words) {
        cin >> word;
    }

    sort(all(words), cmp);

    for (const auto& word: words) {
        cout << word << " ";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
