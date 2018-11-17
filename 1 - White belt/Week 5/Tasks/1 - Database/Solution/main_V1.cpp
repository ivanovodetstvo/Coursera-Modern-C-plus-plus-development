#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <exception>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

bool isValidMonth(const int& month) {
    if (month < 1)
        return false;
    if (month > 12)
        return false;
    return true;
}

bool isValidDay(const int& day) {
    if (day < 1)
        return false;
    if (day > 31)
        return false;
    return true;
}

bool isValidDateString(const string& str) {
    int cnt = 0;
    for (size_t i = 0; i < str.length(); i++) {
        if (!(str[i] == '0' ||
              str[i] == '1' ||
              str[i] == '2' ||
              str[i] == '3' ||
              str[i] == '4' ||
              str[i] == '5' ||
              str[i] == '6' ||
              str[i] == '7' ||
              str[i] == '8' ||
              str[i] == '9' ||
              str[i] == '-' ))
            return false;
        if (str[i] == '-')
            cnt++;
    }
    if (str[str.length()-1] == '-')
        return false;

    return true;
}

vector < string > split(const string &s, const char &delim) {
    stringstream ss(s);
    string item;
    vector < string > elems;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

class Date {
public:
    Date(const int &new_year = 0, const int &new_month = 0, const int &new_day = 0) {
        fillDate(new_year, new_month, new_day);
    }

    Date(const string& new_date) {
        fillDate(new_date);
    }

    void fillDate(const int &new_year = 0, const int &new_month = 0, const int &new_day = 0) {
        this->year = new_year;
        this->month = new_month;
        this->day = new_day;

        FormatDateString();
    }

    void fillDate(const string& new_date) {
        vector < string > splitted = split(new_date, '-');

        if (!isValidDateString(new_date))
            throw "Wrong date format: " + new_date;

        if (splitted.size() < 3 || splitted.size() > 4)
            throw "Wrong date format: " + new_date;

        if (splitted.size() == 4)
            if (splitted[3].length() == 0)
                throw "Wrong date format: " + new_date;

        if (splitted.size() == 4) {
            if (splitted[0].length() == 0) {
                this->year  = -atoi(splitted[1].c_str());
                this->month =  atoi(splitted[2].c_str());
                this->day   =  atoi(splitted[3].c_str());
            } else if (splitted[1].length() == 0) {
                this->year  =  atoi(splitted[0].c_str());
                this->month = -atoi(splitted[2].c_str());
                this->day   =  atoi(splitted[3].c_str());
            } else if (splitted[2].length() == 0) {
                this->year  =  atoi(splitted[0].c_str());
                this->month =  atoi(splitted[1].c_str());
                this->day   = -atoi(splitted[3].c_str());
            } else if (splitted[3].length() == 0) {
                throw "Wrong date format: " + new_date;
            } else {
                throw "Wrong date format: " + new_date;
            }
        } else {
            this->year  = atoi(splitted[0].c_str());
            this->month = atoi(splitted[1].c_str());
            this->day   = atoi(splitted[2].c_str());
        }

        if (!isValidDate())
            throw whatIsInvalid();

        FormatDateString();
    }

    int GetYear() const {
        return this->year;
    }

    string GetYearString() const {
        string ans = to_string(this->year);
        while (ans.length() < 4)
            ans = "0" + ans;

        return ans;
    }

    int GetMonth() const {
        return this->month;
    }

    string GetMonthString() const {
        string ans = to_string(this->month);
        if (ans.length() < 2)
            ans = "0" + ans;

        return ans;
    }

    int GetDay() const {
        return this->day;
    }

    string GetDayString() const {
        string ans = to_string(this->day);
        if (ans.length() < 2)
            ans = "0" + ans;

        return ans;
    }

    string GetDateString() const {
        return this->date;
    }

    bool isValidDate() const {
        return (isValidMonth(this->month) && isValidDay(this->day));
    }

    string whatIsInvalid() const {
        if (!isValidMonth(this->month))
            return "Month value is invalid: " + to_string(this->month);
        if (!isValidDay(this->day))
            return   "Day value is invalid: " + to_string(this->day  );
        return "";
    }

private:
    int year;
    int month;
    int day;
    string date;

    void FormatDateString() {
        this->date = GetYearString() + "-" + GetMonthString() + "-" + GetDayString();
    }
};

bool operator == (const Date& lhs, const Date& rhs) {
    return lhs.GetDateString() == rhs.GetDateString();
}

bool operator != (const Date& lhs, const Date& rhs) {
    return (!(lhs == rhs));
}

bool operator < (const Date& lhs, const Date& rhs) {
//    if (lhs.GetYear() != rhs.GetYear())
//        return lhs.GetYear() < rhs.GetYear();
//
//    if (lhs.GetMonth() != rhs.GetMonth())
//        return lhs.GetMonth() < rhs.GetMonth();
//
//    return lhs.GetDay() < rhs.GetDay();

    return lhs.GetYear()*12*31 + lhs.GetMonth()*31 + lhs.GetDay() <
           rhs.GetYear()*12*31 + rhs.GetMonth()*31 + rhs.GetDay();
}

bool operator > (const Date& lhs, const Date& rhs) {
    return !(lhs == rhs || lhs < rhs);
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (event.length() == 0)
             throw "Wrong date format: " + date.GetDateString();

        this->data[date].insert(event);
    }

    bool DeleteEvent(const Date& date, const string& event) {
        if (this->data[date].count(event)) {
            this->data[date].erase(event);

            if (this->data[date].size() == 0)
                DeleteDate(date);

            return true;
        } else {
//            DeleteDate(date);

            return false;
        }
    }

    int  DeleteDate(const Date& date) {
        int ans;

//        cerr << "event: " << date.GetDateString() << endl;
//        cerr << " size: " << this->data[date].size() << endl;

        ans = this->data[date].size();
        this->data.erase(date);

        return ans;
    }

    void Find(const Date& date) const {
        if (this->data.count(date) > 0)
            if (this->data.at(date).size() > 0)
                for (const auto& event: this->data.at(date))
                    cout << event << endl;
    }

    void Print() const {
		for (const auto& date : data){
			for (auto event : date.second){
				cout << date.first.GetDateString() << ' ' << event << endl;
			}
		}
    }

private:
    map < Date , set < string > > data;
};

int main() {
//    freopen( "input.txt", "r+", stdin );
//    freopen("output.txt", "w+", stdout);

//    cerr << (Date("2017-01-01") < Date("2016-01-02")) << endl;
//    cerr << (Date("2017-01-01") < Date("2016-02-01")) << endl;

    Database db;
/*
    string tmp = "1-1--1";
    vector < string > tmp_vec = split(tmp, '-');
    for (const auto&q: tmp_vec)
        cerr << "|" << q << "| ";
    cerr << endl << endl;
//*/
    string line;
    while (getline(cin, line)) {
        stringstream lineStream(line);

        string command;
        lineStream >> command;
        if (command == "Add") {
            string date, event;
            lineStream >> date >> event;
            Date event_date;

            try {
                event_date.fillDate(date);

                db.AddEvent(event_date, event);
            } catch (string s) {
                cout << s << endl;
            }
        }
        else if (command == "Del") {
            string date;
            lineStream >> date;
            Date event_date;
            string event;
            if (lineStream >> event) {
                try {
                    event_date.fillDate(date);

                    if (db.DeleteEvent(event_date, event))
                        cout << "Deleted successfully" << endl;
                    else
                        cout << "Event not found" << endl;
                } catch (string s) {
                    cout << s << endl;
                }
            } else {
                try {
                    event_date.fillDate(date);

                    cout << "Deleted " << db.DeleteDate(event_date) << " events" << endl;
                } catch (string s) {
                    cout << s << endl;
                }

            }
        }
        else if (command == "Find") {
            string date;
            lineStream >> date;
            Date event_date;

            try {
                event_date.fillDate(date);

                db.Find(event_date);
            } catch (string s) {
                cout << s << endl;
            }
        }
        else if (command == "Print") {
            db.Print();
        } else {
            if (command.length() > 0)
                cout << "Unknown command: " << command << endl;
        }
    }


    fclose(stdin);
    fclose(stdout);

    return 0;
}
