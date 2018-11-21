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
    int16_t r;
    cin >> n >> r;

    int64_t ans = 0;
    int w, h, d;
    for (int i = 0; i < n; i++) {
        cin >> w >> h >> d;
        ans += w*h*d * r;
    }

    cout << ans;

    fclose(stdin);
    fclose(stdout);

    return 0;
}

