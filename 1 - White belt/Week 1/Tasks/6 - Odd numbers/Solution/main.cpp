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

    int a, b;
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if (i % 2 == 0)
            cout << i << " ";

    fclose(stdin);
    fclose(stdout);

    return 0;
}
