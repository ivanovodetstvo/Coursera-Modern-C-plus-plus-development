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

    vector < int > month_size = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int current_month = 0;
    vector < vector < string > > tasks(31 + 1);

    int Q;
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        string command;
        cin >> command;
        if (command == "ADD") {
            int day;
            string task;
            cin >> day >> task;

            tasks[day].push_back(task);
        }
        if (command == "DUMP") {
            int day;
            cin >> day;

            cout << tasks[day].size() << " ";
            for (const auto& task : tasks[day])
                cout << task << " ";

            cout << endl;
        }
        if (command == "NEXT") {
            int new_month = current_month + 1;
            new_month %= 12;

            if (month_size[new_month] >= month_size[current_month]) {
                // do nothing
            } else {
                for (int current_day = month_size[new_month]+1; current_day <= month_size[current_month]; current_day++) {
                    tasks[month_size[new_month]].insert(end(tasks[month_size[new_month]]), all(tasks[current_day]));
                    tasks[current_day].clear();
                }
            }

            current_month = new_month;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

