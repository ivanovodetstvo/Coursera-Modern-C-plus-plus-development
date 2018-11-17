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

    string s;
    cin >> s;

    int occurance = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'f')
            occurance++;
        if (occurance == 2) {
            cout << i;
            return 0;
        }
    }
    if (occurance == 1)
        cout << -1;
    else
        cout << -2;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
