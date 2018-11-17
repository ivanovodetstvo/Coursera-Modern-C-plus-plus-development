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

    map < string , string > capitals;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string task;
        cin >> task;

        if (task == "CHANGE_CAPITAL") {
            string country, new_capital;
            cin >> country >> new_capital;
            if (capitals.count(country) == 0) {
                cout << "Introduce new country " << country << " with capital " << new_capital << endl;
            } else {
                if (capitals[country] == new_capital) {
                    cout << "Country " << country << " hasn't changed its capital" << endl;
                } else {
                    cout << "Country " << country << "  has changed its capital from " << capitals[country] << " to " << new_capital << endl;
                }
            }
            capitals[country] = new_capital;
        }
        if (task == "RENAME") {
            string old_country_name, new_country_name;
            cin >> old_country_name >> new_country_name;
            if ((old_country_name == new_country_name) ||
                (capitals.count(old_country_name) == 0) ||
                (capitals.count(new_country_name) == 1)) {
                cout << "Incorrect rename, skip" << endl;
            } else {
                cout << "Country " << old_country_name << " with capital " << capitals[old_country_name] << " has been renamed to " << new_country_name << endl;
                capitals[new_country_name] = capitals[old_country_name];
                capitals.erase(old_country_name);
            }
        }
        if (task == "ABOUT") {
            string country;
            cin >> country;

            if (capitals.count(country) == 0) {
                cout << "Country " << country << " doesn't exist" << endl;
            } else {
                cout << "Country " << country << " has capital " << capitals[country] << endl;
            }
        }
        if (task == "DUMP") {
            if (capitals.size() == 0) {
                cout << "There are no countries in the world" << endl;
            } else {
                for (const auto& data : capitals)
                    cout << data.first << "/" << data.second << " ";
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

