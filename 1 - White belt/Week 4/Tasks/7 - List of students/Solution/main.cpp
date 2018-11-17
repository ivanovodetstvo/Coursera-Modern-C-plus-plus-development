#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

struct Student {
    string name;
    string birthday;
};

int main() {
    int n;
    cin >> n;

    string first_name, last_name, day, month, year;
    vector < Student > students;
    for (size_t i = 0; i < n; i++) {
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back(Student{first_name + " " + last_name, day + "." + month + "." + year});
    }

    int m;
    cin >> m;
    string query;
    int student_number;

    for (int i = 0; i < m; ++i) {
        cin >> query >> student_number;
        student_number--;
        if (student_number >= 0 && student_number < n) {
            if (query == "name") {
                cout << students[student_number].name << endl;
            }
            if (query == "date") {
                cout << students[student_number].birthday << endl;
            }
            if (query != "name" && query != "date") {
                cout << "bad request" << endl;
            }
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}

