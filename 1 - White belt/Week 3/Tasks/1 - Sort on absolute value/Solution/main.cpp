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

bool cmp(const int &a, const int &b) {
    return abs(a) < abs(b);
}

int main() {
//    freopen("INPUT.TXT", "r+", stdin);
//    freopen("OUTPUT.TXT", "w+", stdout);

    int n;
    cin >> n;
    vector < int > nums(n);
    for (auto& num: nums) {
        cin >> num;
    }

    sort(all(nums), cmp);

    for (const auto& num: nums) {
        cout << num << " ";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

