#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

int main() {
    freopen("input.txt", "r+", stdin);
//    freopen("output.txt", "w+", stdout);

    string s;
    while (
           getline(cin, s)
           ) {
        cout << s << "\n";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
