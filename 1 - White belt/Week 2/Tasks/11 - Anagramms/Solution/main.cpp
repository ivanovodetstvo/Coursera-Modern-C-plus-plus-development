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

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string word1, word2;
        cin >> word1 >> word2;

        map < char , int > word1_map, word2_map;
        for (const auto& c : word1)
            word1_map[c]++;
        for (const auto& c : word2)
            word2_map[c]++;

        if (word1_map == word2_map)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        word1_map.clear();
        word2_map.clear();
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

