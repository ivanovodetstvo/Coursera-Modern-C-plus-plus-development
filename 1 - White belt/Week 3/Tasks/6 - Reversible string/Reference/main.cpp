#include <algorithm>
#include <string>

class ReversibleString {
public:
  ReversibleString() {}
  ReversibleString(const string& s) {
    data = s;
  }
  void Reverse() {
    reverse(begin(data), end(data));
  }
  string ToString() const {
    return data;
  }
private:
  string data;
};
