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

    vector < bool > my_queue;

    int operations;
    cin >> operations;
    for (int i = 0; i < operations; i++) {
        string command;
        cin >> command;
        if (command == "WORRY") {
            int argument;
            cin >> argument;

            my_queue[argument] = true;
        }

        if (command == "QUIET") {
            int argument;
            cin >> argument;

            my_queue[argument] = false;
        }

        if (command == "COME") {
            int argument;
            cin >> argument;

            if (argument > 0) {
                my_queue.resize(my_queue.size() + argument);
            }

            if (argument < 0) {
                my_queue.resize(my_queue.size() + argument);
            }
        }

        if (command == "WORRY_COUNT") {
            int ans = 0;
            for (auto person : my_queue)
                if (person)
                    ans++;
            cout << ans << endl;
        }
    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}

