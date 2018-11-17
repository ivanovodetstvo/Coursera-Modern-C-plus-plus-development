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

    int days;
    double average = 0;
    cin >> days;
    vector < int > temperatures(days);

    for (size_t i = 0; i < temperatures.size(); i++) {
        cin >> temperatures[i];
        average += temperatures[i];
    }
    average /= days;

    int ammount = 0;
    for (size_t i = 0; i < temperatures.size(); i++) {
        if (temperatures[i] > average)
            ++ammount;
    }

    cout << ammount << endl;
    for (size_t i = 0; i < temperatures.size(); i++) {
        if (temperatures[i] > average)
            cout << i << " ";
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

