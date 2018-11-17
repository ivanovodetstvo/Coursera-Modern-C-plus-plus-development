#include <algorithm>
#include <vector>

using namespace std;

class FunctionPart {
public:
    FunctionPart(const char &new_operation, const double &new_value) {
        operation = new_operation;
        value = new_value;
    }

    double Apply(const double &source_value) const {
        if (operation == '+') {
            return source_value + value;
        }
        if (operation == '-') {
            return source_value - value;
        }
        return 0;
    }

    void Invert() {
        if (operation == '+') {
            operation =  '-';
            return;
        }
        if (operation == '-') {
            operation =  '+';
            return;
        }
    }

private:
    char operation;
    double value;
};

class Function {
public:
    void AddPart(const char &operation, const double &value) {
        parts.push_back({operation, value});
    }

    double Apply(const double &value) const {
        double new_value = value;
        for (const FunctionPart& part : parts) {
            new_value = part.Apply(new_value);
        }
        return new_value;
    }

    void Invert() {
        for (FunctionPart& part : parts) {
            part.Invert();
        }
        reverse(begin(parts), end(parts));
    }

private:
    vector < FunctionPart > parts;
};
