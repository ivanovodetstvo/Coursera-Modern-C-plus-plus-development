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
#include <stdexcept>

#define all(c) c.begin(), c.end()
#define EPS 1E-7

using namespace std;

class Matrix {
private:
	int rows;
	int columns;

	vector < vector < int > > matrix;

public:
	Matrix(int new_rows = 0, int new_columns = 0) {
		Reset(new_rows, new_columns);
	}

	~Matrix() {
		for (int row = 0; row < GetNumRows(); row++) {
			matrix[row].clear();
		}
		matrix.clear();

		rows = -1;
		columns = -1;
	}

	void Reset(int new_rows, int new_columns) {
		if (new_rows < 0) {
			throw out_of_range("new_rows must be >= 0");
		}
		if (new_columns < 0) {
			throw out_of_range("new_columns must be >= 0");
		}

		rows = new_rows;
		columns = new_columns;
		matrix.assign(new_rows, vector < int > (new_columns));
	}

	int& At(int row, int column) {
		return matrix.at(row).at(column);
	}

	int At(int row, int column) const {
		return matrix.at(row).at(column);
	}

	int GetNumRows() const {
		return rows;
	}

	int GetNumColumns() const {
		return columns;
	}
};

bool operator == (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		return false;
	}

	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		return false;
	}

	for (int row = 0; row < lhs.GetNumRows(); ++row) {
		for (int column = 0; column < lhs.GetNumColumns(); ++column) {
			if (lhs.At(row, column) != rhs.At(row, column)) {
				return false;
			}
		}
	}

	return true;
}

bool operator != (const Matrix& lhs, const Matrix& rhs) {
	return (!(lhs == rhs));
}

Matrix operator + (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}

	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}

	Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

	for (int row = 0; row < result.GetNumRows(); row++) {
		for (int column = 0; column < result.GetNumColumns(); column++) {
			result.At(row, column) = lhs.At(row, column) + rhs.At(row, column);
		}
	}

	return result;
}

Matrix operator - (const Matrix& lhs, const Matrix& rhs) {
	if (lhs.GetNumRows() != rhs.GetNumRows()) {
		throw invalid_argument("Mismatched number of rows");
	}

	if (lhs.GetNumColumns() != rhs.GetNumColumns()) {
		throw invalid_argument("Mismatched number of columns");
	}

	Matrix result(lhs.GetNumRows(), lhs.GetNumColumns());

	for (int row = 0; row < result.GetNumRows(); row++) {
		for (int column = 0; column < result.GetNumColumns(); column++) {
			result.At(row, column) = lhs.At(row, column) - rhs.At(row, column);
		}
	}

	return result;
}

istream& operator >> (istream& in, Matrix& matrix) {
	int new_rows, new_columns;

	in >> new_rows >> new_columns;

	matrix.Reset(new_rows, new_columns);
	for (int row = 0; row < new_rows; ++row) {
		for (int column = 0; column < new_columns; ++column) {
			in >> matrix.At(row, column);
		}
	}

	return in;
}

ostream& operator << (ostream& out, const Matrix& matrix) {
	out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;

	for (int row = 0; row < matrix.GetNumRows(); ++row) {
		for (int column = 0; column < matrix.GetNumColumns(); ++column) {
			if (column > 0) {
				out << " ";
			}
			out << matrix.At(row, column);
		}
		out << endl;
	}

	return out;
}

int main() {
//    freopen( "input.txt", "r+", stdin );
//    freopen("output.txt", "w+", stdout);

	Matrix m1;
	Matrix m2;

	cin >> m1 >> m2;
	cout << m1 + m2 << endl;

    fclose(stdin);
    fclose(stdout);

	return 0;
}
