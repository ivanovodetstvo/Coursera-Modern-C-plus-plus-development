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

    double a, b, c;
    cin >> a >> b >> c;
    if (a == 0 && b == 0 && c == 0) {
        cout << "INF ROOTS"; // NO SUCH TEST
    } else {
        if (a == 0 && b == 0 && c != 0) {
            cout << ""; // NO ROOTS
        } else {
            if (a == 0) {
                cout << -c / b;
            } else {
                double d = b*b - 4*a*c;
                if (d < -EPS) {
                    cout << ""; // NO ROOTS
                } else {
                    if (abs(d) < EPS) {
                        cout << - b / (2.0 * a);
                    } else {
                        cout << (-b + sqrt(d)) / (2.0 * a);
                        cout << " ";
                        cout << (-b - sqrt(d)) / (2.0 * a);
                    }
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
