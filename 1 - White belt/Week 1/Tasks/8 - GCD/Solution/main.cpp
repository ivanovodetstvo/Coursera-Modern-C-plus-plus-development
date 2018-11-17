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

int GCD(int a, int b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

int main() {
//    freopen("INPUT.TXT", "r+", stdin);
//    freopen("OUTPUT.TXT", "w+", stdout);

    int a, b;
    cin >> a >> b;
    cout << GCD(a, b);

    fclose(stdin);
    fclose(stdout);

    return 0;
}
