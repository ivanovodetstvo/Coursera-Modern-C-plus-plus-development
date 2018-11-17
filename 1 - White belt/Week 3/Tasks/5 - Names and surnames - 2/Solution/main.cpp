#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>


class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        map_first_name[year] = first_name;
    }

    void ChangeLastName(int year, const string& last_name) {
        map_last_name[year] = last_name;
    }

    string GetFullName(int year) {
        string ans = "";

//        cerr << "For year: " << year;
        string f_name = getName(year, map_first_name);
        string l_name = getName(year, map_last_name);
//        cerr << ", first name = " << f_name << ", last name = " << l_name << endl;

        if (f_name == "" && l_name == "") {
            ans = "Incognito";
        }
        if (f_name == "" && l_name != "") {
            ans = l_name + " with unknown first name";
        }
        if (f_name != "" && l_name == "") {
            ans = f_name + " with unknown last name";
        }
        if (f_name != "" && l_name != "") {
            ans = f_name + " " + l_name;
        }

        return ans;
    }

    string GetFullNameWithHistory(int year) {
        string ans = "";

//        cerr << "For year: " << year;
        string f_name = getNameWithHistory(year, map_first_name);
        string l_name = getNameWithHistory(year, map_last_name);
//        cerr << ", first name = " << f_name << ", last name = " << l_name << endl;

        if (f_name == "" && l_name == "") {
            ans = "Incognito";
        }
        if (f_name == "" && l_name != "") {
            ans = l_name + " with unknown first name";
        }
        if (f_name != "" && l_name == "") {
            ans = f_name + " with unknown last name";
        }
        if (f_name != "" && l_name != "") {
            ans = f_name + " " + l_name;
        }

        return ans;
    }

private:
    map < int , string > map_first_name;
    map < int , string > map_last_name;

    string getName(const int &year, const map < int , string > &name) {
        string ans = "";

        for(const auto& current_name: name) {
            if (current_name.first <= year) {
                ans = current_name.second;
            } else {
                break;
            }
        }

        return ans;
    }

    string getNameWithHistory(const int &year, const map < int , string > &name) {
        string ans = "";
        vector < string > temp;

        for(const auto& current_name: name) {
            if (current_name.first <= year) {
                if (temp.size() == 0) {
                    temp.push_back(current_name.second);
                    continue;
                }
                if (current_name.second != temp[temp.size() - 1]) {
                    temp.push_back(current_name.second);
                }
            }
            if (current_name.first > year) {
                break;
            }
        }

        if (temp.size() > 0) {
            if (temp.size() > 1) {
                for (int i = temp.size() - 2; i >= 0; i--) {
                    ans += temp[i];
                    if (i != 0)
                        ans += ", ";
                }
                ans = temp[temp.size() - 1] + " (" + ans + ")";
            } else {
                ans = temp[temp.size() - 1];
            }
        }

        return ans;
    }
};
