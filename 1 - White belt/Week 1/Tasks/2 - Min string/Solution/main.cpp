#include <algorithm>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>

#define all(c) c.begin(), c.end()

using namespace std;

int main() {
//    freopen("INPUT.TXT", "r+", stdin);
//    freopen("OUTPUT.TXT", "w+", stdout);

    string a, b, c;
    cin >> a >> b >> c;
    cout << min(min(a, b), c);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
