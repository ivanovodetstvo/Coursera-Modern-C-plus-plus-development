
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

    set < string > strings;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        strings.insert(str);
    }

    cout << strings.size();

    fclose(stdin);
    fclose(stdout);

    return 0;
}
