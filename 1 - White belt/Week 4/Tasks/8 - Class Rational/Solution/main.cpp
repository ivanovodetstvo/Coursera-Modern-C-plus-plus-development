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

using namespace std;

class Rational {
public:
    Rational(int new_numerator = 0, int new_denominator = 1) {
        this->numerator = new_numerator;
        this->denominator = new_denominator;

        if (this->denominator == 0)
            this->numerator = 0;

        if (this->numerator == 0)
            this->denominator = 1;

        if (denominator < 0) {
            this->numerator *= -1;
            this->denominator *= -1;
        }

        Reduce();
    }

    int Numerator() const {
        return this->numerator;
    }

    int Denominator() const {
        return this->denominator;
    }

    Rational invert() const {
        return Rational(this->denominator, this->numerator);
    }

private:
    int numerator;
    int denominator;

    int GCD(int a, int b) {
        while (b) {
            a %= b;
            swap(a, b);
        }
        return a;
    }

    int LCM(int a, int b) {
        return a * b / GCD(a, b);
    }

    void Reduce() {
        int gcd = GCD(abs(this->numerator), abs(this->denominator));

        this->numerator   /= gcd;
        this->denominator /= gcd;

        return;
    }
};

bool operator == (const Rational& lhs, const Rational& rhs) {
    return ((lhs.Numerator()   == rhs.Numerator()  ) &&
            (lhs.Denominator() == rhs.Denominator()));
}

bool operator != (const Rational& lhs, const Rational& rhs) {
    return (!(lhs == rhs));
}

bool operator < (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() < rhs.Numerator() * lhs.Denominator());
}

bool operator > (const Rational& lhs, const Rational& rhs) {
    return (lhs.Numerator() * rhs.Denominator() > rhs.Numerator() * lhs.Denominator());
}

Rational operator + (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() + rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator - (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Denominator() - rhs.Numerator() * lhs.Denominator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator * (const Rational& lhs, const Rational& rhs) {
    return Rational(lhs.Numerator() * rhs.Numerator(), lhs.Denominator() * rhs.Denominator());
}

Rational operator / (const Rational& lhs, const Rational& rhs) {
    return lhs * rhs.invert();
}

ostream& operator << (ostream& stream, const Rational& rational) {
    stream << rational.Numerator() << "/" << rational.Denominator();
    return stream;
}

istream& operator >> (istream& stream, Rational& rational) {
    if (stream.tellg() != -1) {
        int numerator, denominator;
        stream >> numerator;
        stream.ignore(1);
        stream >> denominator;
        rational = Rational(numerator, denominator);
    }
    return stream;
}
