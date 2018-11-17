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

    double a, b, x, y, n;
    cin >> n >> a >> b >> x >> y;

    double ans = n;

    if (n > a)
        ans = n*(1 - x/100.);
    if (n > b)
        ans = n*(1 - y/100.);

    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
