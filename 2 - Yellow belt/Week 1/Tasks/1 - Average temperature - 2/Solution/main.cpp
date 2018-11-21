#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <exception>
#include <stdexcept>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

int main() {
//    freopen( "input.txt", "r+", stdin );
//    freopen("output.txt", "w+", stdout);

    int n;
    cin >> n;
    vector < int64_t > temperatures(n);
    long double average = 0;
    for (auto& current_temperature: temperatures) {
        cin >> current_temperature;
        average += current_temperature / n;
    }

    for (int i = 0; i < n; i++) {
        if (temperatures[i] > average) {
            cout << i << " ";
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

