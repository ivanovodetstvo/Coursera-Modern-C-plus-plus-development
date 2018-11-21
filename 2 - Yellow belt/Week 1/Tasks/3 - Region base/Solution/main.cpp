#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <cstdint>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <tuple>
#include <utility>
#include <exception>
#include <stdexcept>

using namespace std;

/*
enum class Lang {
    DE, FR, IT
};

struct Region {
    string std_name;
    string parent_std_name;
    map < Lang, string > names;
    int64_t population;
};
*/

bool operator < (const Region &lhs, const Region &rhs) {
    return tie(lhs.std_name, lhs.parent_std_name, lhs.names, lhs.population) <
           tie(rhs.std_name, rhs.parent_std_name, rhs.names, rhs.population);
}

int FindMaxRepetitionCount(const vector < Region > &regions) {
    int result = 0;
    map < Region, int > repetion_count;
    for (const auto& region: regions) {
        result = max(result, ++repetion_count[region]);
    }
    return result;
}
