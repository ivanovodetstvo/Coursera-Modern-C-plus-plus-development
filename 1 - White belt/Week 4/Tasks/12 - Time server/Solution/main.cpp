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

class TimeServer {
public:
    string GetCurrentTime() {
        try {
            this->LastFetchedTime = AskTimeServer();
        } catch (system_error&) {

        }

        return this->LastFetchedTime;
    }

private:
    string LastFetchedTime = "00:00:00";
};
