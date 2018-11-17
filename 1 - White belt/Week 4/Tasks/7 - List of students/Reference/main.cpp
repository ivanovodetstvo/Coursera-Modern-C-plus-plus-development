#include <iostream>
#include <string>
#include <vector>
#include <utility>

using namespace std;

struct Student {
    string name;
    string birthday;
};

int main() {
    int n;
    cin >> n;

    string first_name, last_name, day, month, year;
    vector<Student> students;
    for (size_t i = 0; i < n; ++i) {
        cin >> first_name >> last_name >> day >> month >> year;
        students.push_back(Student{first_name + " " + last_name,
                                    day + "." + month + "." + year});
    }

    int m;
    cin >> m;
    string query;
    int student_number;

    for (int i = 0; i < m; ++i) {
        cin >> query >> student_number;
        --student_number;
        if (query == "name" && student_number >=0 && student_number < n) {
            cout << students[student_number].name << endl;
        } else if (query == "date" && student_number >=0
                    && student_number < n) {
            cout << students[student_number].birthday << endl;
        } else {
            cout << "bad request" << endl;
        }
    }

    return 0;
}
