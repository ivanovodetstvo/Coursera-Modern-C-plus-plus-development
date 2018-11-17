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

    map < vector < string > , int > routes;
    int n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        vector < string > route(k);
        for (int j = 0; j < k; j++) {
            cin >> route[j];
        }

        if (routes.count(route) > 0) {
            cout << "Already exists for " << routes[route] << endl;
        } else {
            int new_route_number = routes.size() + 1;
            routes[route] = new_route_number;
            cout << "New bus " << routes[route] << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

