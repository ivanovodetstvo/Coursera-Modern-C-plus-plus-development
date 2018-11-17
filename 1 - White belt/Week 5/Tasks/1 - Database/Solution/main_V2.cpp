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

// Реализуйте функции и методы классов и при необходимости добавьте свои

vector < string > split(const string &s, const char &delim) {
    stringstream ss(s);
    string item;
    vector < string > elems;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return elems;
}

bool isValidDateStringSymbolsExternal(const string& str) {
    int cnt = 0;

    set < char > allowedSymbols = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '-'};

    for (const auto& c: str) {
        if (allowedSymbols.count(c) == 0) {
            return false;
        }

        if (c == '-') {
            cnt++;
        }
    }

    if (cnt < 2) {
        return false;
    }
    if (cnt > 3) {
        return false;
    }

    if (str[str.length() - 1] == '-') {
        return false;
    }

    vector < string > str_split = split(str, '-');
    if (str[0] != '-') {
        for (const auto& s: str_split) {
            if (s.length() == 0){
//                return false;
            }
        }
    }

    if (cnt == 2) {
        if (atoi(str_split[1].c_str()) == 0)
            throw "Month value is invalid: " + str_split[1];
        if (atoi(str_split[2].c_str()) == 0)
            throw   "Day value is invalid: " + str_split[2];
    }

    if (cnt == 3) {
        if (str_split[0].length() == 0 &&
            str_split[1].length() != 0 &&
            str_split[2].length() != 0 &&
            str_split[3].length() != 0) {
            if (atoi(str_split[2].c_str()) == 0)
                throw "Month value is invalid: -" + str_split[2];
            if (atoi(str_split[3].c_str()) == 0)
                throw   "Day value is invalid: -" + str_split[3];
        } else if (str_split[0].length() != 0 &&
                   str_split[1].length() == 0 &&
                   str_split[2].length() != 0 &&
                   str_split[3].length() != 0) {
            throw "Month value is invalid: -" + str_split[2];
        } else if (str_split[0].length() != 0 &&
                   str_split[1].length() != 0 &&
                   str_split[2].length() == 0 &&
                   str_split[3].length() != 0) {
            throw "Day value is invalid: -"   + str_split[3];
        }
    }

    return true;
}

class Date {
public:
    Date(const int& new_year  = 1,
         const int& new_month = 1,
         const int& new_day   = 1) {
        fillDate(new_year, new_month, new_day);
    }

    int GetYear() const {
        return this->year;
    }

    string GetYearString() const {
        return AppendZeros(to_string(GetYear()), 4);
    }

    int GetMonth() const {
        return this->month;
    }

    string GetMonthString() const {
        return AppendZeros(to_string(GetMonth()), 2);
    }

    int GetDay() const {
        return this->day;
    }

    string GetDayString() const {
        return AppendZeros(to_string(GetDay()), 2);
    }

    string GetDateString() const {
        return this->dateString;
    }

    void fillDate(const int& new_year  = 0,
                  const int& new_month = 0,
                  const int& new_day   = 0) {
        this->year  = new_year ;
        this->month = new_month;
        this->day   = new_day  ;

        if (!isValidMonth(GetMonth()))
            throw "Month value is invalid: " + GetMonthString();

        if (!isValidDay(GetDay()))
            throw "Day value is invalid: " + GetDayString();

        fillDateString();

        return;
    }

private:
    int year;
    int month;
    int day;

    string dateString = "";

    void fillDateString() {
        this->dateString = GetYearString() + "-" + GetMonthString() + "-" + GetDayString();

        return;
    }

    bool isValidDay(const int &new_day) const {
        if (new_day < 1)
            return false;
        if (new_day > 31)
            return false;
        return true;
    }

    bool isValidMonth(const int &new_month) const {
        if (new_month < 1)
            return false;
        if (new_month > 12)
            return false;
        return true;
    }

    bool isValidDateStringSymbols(const string& str) const {
        return isValidDateStringSymbolsExternal(str);
    }

    string AppendZeros(const string& str, const int& length) const {
        string ans = str;

        while ((int) ans.length() < length) {
            ans = "0" + ans;
        }

        return ans;
    }
};

bool operator == (const Date& lhs, const Date& rhs) {
    return lhs.GetDateString() == rhs.GetDateString();
}

bool operator != (const Date& lhs, const Date& rhs) {
    return !(lhs == rhs);
}

bool operator < (const Date& lhs, const Date& rhs) {
    if (lhs.GetYear() != rhs.GetYear()) {
        return lhs.GetYear() < rhs.GetYear();
    }
    if (lhs.GetMonth() != rhs.GetMonth()) {
        return lhs.GetMonth() < rhs.GetMonth();
    }
    return lhs.GetDay() < rhs.GetDay();
}

bool operator > (const Date& lhs, const Date& rhs) {
    return !(lhs == rhs || lhs < rhs);
}

ostream& operator << (ostream& stream, const Date& date){
	stream << setfill('0') << setw(4) << to_string(date.GetYear());
	stream << "-";
	stream << setfill('0') << setw(2) << to_string(date.GetMonth());
	stream << "-";
	stream << setfill('0') << setw(2) << to_string(date.GetDay());
	return stream;
}

istream& operator >> (istream& stream, Date& date){
    int new_year  = 0;
    int new_month = 0;
    int new_day   = 0;

	string input_string;
	stream >> input_string;

    if (!isValidDateStringSymbolsExternal(input_string))
        throw "Wrong date format: " + input_string;

	stringstream istream(input_string);

	istream >> new_year;
	istream.ignore(1);
	istream >> new_month;
	istream.ignore(1);
	istream >> new_day;

    date.fillDate(new_year, new_month, new_day);

    return stream;
}

class Database {
public:
    void AddEvent(const Date& date, const string& event) {
        if (!event.empty()) {
            database[date].insert(event);
        }
    }

    bool DeleteEvent(const Date& date, const string& event) {
		if (database[date].erase(event) > 0)
			return true;
		else
			return false;
    }

    int DeleteDate(const Date& date) {
		int ans = 0;
		if (database.count(date) > 0){
			ans = database.at(date).size();
			database.erase(date);
		}
		return ans;
    }

    set < string > Find(const Date& date) const {
		set < string > ans;
		if (database.count(date ) > 0){
			ans = database.at(date);
		}
		return ans;
    }

    void Print() const {
		for (const auto& date : database){
			for (auto event : date.second){
				cout << date.first << ' ' << event << endl;
			}
		}
    }

public:
    map < Date , set < string > > database;
};

int main() {
//    freopen( "input.txt", "r+", stdin );
//    freopen("output.txt", "w+", stdout);

    bool unitTest = true;
    if (unitTest) {
        {
            cout << "Comparator test:" << endl;

            cout << ((Date(2017,02,02) == Date(2017,02,02)) == 1) << " ";
            cout << ((Date(2017,02,02) == Date(2016,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) == Date(2017,01,02)) == 0) << " ";
            cout << ((Date(2017,02,02) == Date(2017,02,01)) == 0) << " ";
            cout << ((Date(2017,02,02) == Date(2018,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) == Date(2017,03,02)) == 0) << " ";
            cout << ((Date(2017,02,02) == Date(2017,02,03)) == 0) << " ";

            cout << ((Date(2017,02,02) != Date(2017,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) != Date(2016,02,02)) == 1) << " ";
            cout << ((Date(2017,02,02) != Date(2017,01,02)) == 1) << " ";
            cout << ((Date(2017,02,02) != Date(2017,02,01)) == 1) << " ";
            cout << ((Date(2017,02,02) != Date(2018,02,02)) == 1) << " ";
            cout << ((Date(2017,02,02) != Date(2017,03,02)) == 1) << " ";
            cout << ((Date(2017,02,02) != Date(2017,02,03)) == 1) << " ";

            cout << ((Date(2017,02,02) < Date(2017,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) < Date(2016,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) < Date(2017,01,02)) == 0) << " ";
            cout << ((Date(2017,02,02) < Date(2017,02,01)) == 0) << " ";
            cout << ((Date(2017,02,02) < Date(2018,02,02)) == 1) << " ";
            cout << ((Date(2017,02,02) < Date(2017,03,02)) == 1) << " ";
            cout << ((Date(2017,02,02) < Date(2017,02,03)) == 1) << " ";

            cout << ((Date(2017,02,02) > Date(2017,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) > Date(2016,02,02)) == 1) << " ";
            cout << ((Date(2017,02,02) > Date(2017,01,02)) == 1) << " ";
            cout << ((Date(2017,02,02) > Date(2017,02,01)) == 1) << " ";
            cout << ((Date(2017,02,02) > Date(2018,02,02)) == 0) << " ";
            cout << ((Date(2017,02,02) > Date(2017,03,02)) == 0) << " ";
            cout << ((Date(2017,02,02) > Date(2017,02,03)) == 0) << " ";


            cout << endl << "Done!" << endl << endl;
        }

        {
            cout << "Split test:" << endl;

            cout << (split("1-1-1",   '-') == vector < string > {"1", "1", "1"}    ) << " ";
            cout << (split("-1-1-1",  '-') == vector < string > {"", "1", "1", "1"}) << " ";
            cout << (split("1-1-1-",  '-') == vector < string > {"1", "1", "1"}    ) << " ";
            cout << (split("-1-1-1-", '-') == vector < string > {"", "1", "1", "1"}) << " ";

            cout << (split("1-1-1",   '-') == vector < string > {"1", "1", "1"}    ) << " ";

            cout << endl << "Done!" << endl << endl;
        }

        {
            cout << "String validation test:" << endl;

            cout << (isValidDateStringSymbolsExternal("1-1-1")   == 1) << " ";
            cout << (isValidDateStringSymbolsExternal("-1-1-1")  == 1) << " ";
            cout << (isValidDateStringSymbolsExternal("1-1-1-")  == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("-1-1-1-") == 0) << " ";

            cout << (isValidDateStringSymbolsExternal("1-2-3*ff")  == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("1-0")       == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("1-0-9-")    == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("2001-9-0-") == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("a1-1-1")    == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("a1-1-1a")   == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("-")         == 0) << " ";
            cout << (isValidDateStringSymbolsExternal("0")         == 0) << " ";

            cout << endl << "Done!" << endl << endl;
        }

        {
            cout << "Date reading test:" << endl;

            string input_string;
            Date tempDate;

            {
                input_string = "2018-11-08";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << (tempDate.GetDateString() == input_string) << " ";
            }

            {
                input_string = "2018-11-8";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << (tempDate.GetDateString() == "2018-11-08") << " ";
            }

            {
                input_string = "-2018-11-8";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << (tempDate.GetDateString() == "-2018-11-08") << " ";
            }

            {
                input_string = "2018-11-008";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << (tempDate.GetDateString() == "2018-11-08") << " ";
            }

            try {
                input_string = "2018-11a8";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Wrong date format: " + input_string) << " ";
            }

            try {
                input_string = "2018--11-1";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Month value is invalid: -11") << " ";
            }

            try {
                input_string = "2018-0-1";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Month value is invalid: 0") << " ";
            }

            try {
                input_string = "2018-13-1";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Month value is invalid: 13") << " ";
            }

            try {
                input_string = "2018-11--1";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Day value is invalid: -1") << " ";
            }

            try {
                input_string = "2018-11-0";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Day value is invalid: 0") << " ";
            }

            try {
                input_string = "2018-11-33";
                stringstream input_stream(input_string);
                input_stream >> tempDate;
                cout << "0" << " ";
            } catch (string s) {
                cout << (s == "Day value is invalid: 33") << " ";
            }

            cout << endl << "Done!" << endl << endl;
        }

        return 0;
    }

    Database db;

    string inputLine;
    while (getline(cin, inputLine)) {

    }

    fclose(stdin);
    fclose(stdout);

    return 0;
}
