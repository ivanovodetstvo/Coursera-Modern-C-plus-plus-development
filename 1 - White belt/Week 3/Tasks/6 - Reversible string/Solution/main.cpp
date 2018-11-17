#include <algorithm>
#include <string>

class ReversibleString {
public:
    ReversibleString(const string& s = "") {
        str = s;
    }

    void Reverse() {
        reverse(begin(str), end(str));
    }

    string ToString() const {
        return str;
    }

private:
    string str;
};
