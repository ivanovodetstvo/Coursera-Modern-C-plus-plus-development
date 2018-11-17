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

    int q;
    cin >> q;

    map < string , vector < string > > routes;
    map < string , vector < string > > buses_for_stop;

    for (int qq = 0; qq < q; qq++) {
        string command;
        cin >> command;

        if (command == "NEW_BUS") {
            string bus;
            cin >> bus;

            int stop_count;
            cin >> stop_count;

            for (int i = 0; i < stop_count; i++) {
                string stop;
                cin >> stop;

                routes[bus].push_back(stop);
                buses_for_stop[stop].push_back(bus);
            }
        }
        if (command == "BUSES_FOR_STOP") {
            string stop;
            cin >> stop;

            if (buses_for_stop[stop].size() == 0) {
                cout << "No stop" << endl;
            } else {
                for (const auto& bus : buses_for_stop[stop]) {
                    cout << bus << " ";
                }
                cout << endl;
            }
        }
        if (command == "STOPS_FOR_BUS") {
            string bus;
            cin >> bus;

            if (routes.count(bus) == 0) {
                cout << "No bus" << endl;
            } else {
                for (int i = 0; i < routes[bus].size(); i++) {
                    cout << "Stop " << routes[bus][i] << ": ";

                    if (buses_for_stop[routes[bus][i]].size() == 1) {
                        cout << "no interchange";
                    } else {
                        for (int j = 0; j < buses_for_stop[routes[bus][i]].size(); j++) {
                            if (buses_for_stop[routes[bus][i]][j] != bus)
                                cout << buses_for_stop[routes[bus][i]][j] << " ";
                        }
                    }

                    cout << endl;
                }
            }
        }
        if (command == "ALL_BUSES") {
            if (routes.size() == 0) {
                cout << "No buses" << endl;
            } else {
                for (const auto& route : routes) {
                    cout << "Bus " << route.first << ": ";
                    for (int i = 0; i < route.second.size(); i++) {
                        cout << route.second[i] << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
