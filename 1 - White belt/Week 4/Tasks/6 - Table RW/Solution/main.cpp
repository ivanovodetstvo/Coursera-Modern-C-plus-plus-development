#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

void Append(string &s) {
    while (s.length() < 0)
        s = " " + s;
}

int main() {
    freopen( "input.txt", "r+", stdin );
//    freopen("output.txt", "w+", stdout);

    int n, m;
//*
    cin >> n >> m;
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            getline(cin, s, ',');
//            cerr << "         s = |" << s << "|" << endl;
            Append(s);
//            cerr << "Appended s = |" << s << "|" << endl;
             cout << setw(10) << stoi(s);
             cout << " ";
        }
        cin >> s;
        Append(s);
        cout << setw(10) << stoi(s);

        if (i != n-1)
            cout << "\n";

        getline(cin, s);
    }

    fclose(stdin);
    fclose(stdout);
//*/
    return 0;
}
