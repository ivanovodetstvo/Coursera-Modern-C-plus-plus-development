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

    vector < int > ans;
    int n;
    cin >> n;

    while (n) {
        ans.push_back(n % 2);
        n /= 2;
    }
    reverse(all(ans));
    for (auto i : ans)
        cout << i;

    fclose(stdin);
    fclose(stdout);

    return 0;
}
