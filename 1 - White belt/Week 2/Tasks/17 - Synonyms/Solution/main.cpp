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

int main() {
//    freopen("INPUT.TXT", "r+", stdin);
//    freopen("OUTPUT.TXT", "w+", stdout);

    map < string , set < string > > synonyms;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;

        if (command == "ADD") {
            string word1, word2;
            cin >> word1 >> word2;

            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        }
        if (command == "COUNT") {
            string word;
            cin >> word;

            cout << synonyms[word].size() << endl;
        }
        if (command == "CHECK") {
            string word1, word2;
            cin >> word1 >> word2;

            if ((synonyms[word1].count(word2) == 1) ||
                (synonyms[word2].count(word1) == 1))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

