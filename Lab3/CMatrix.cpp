#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "CMatrix.h"

using namespace std;

int CMatrix::count = 0;
char msg[100];

CMatrix::CMatrix() {
	setMatrix(0, 0, NULL);
	id = ++count;
	printf("Constructor 1: Matrix %d\n\n", id);
}

CMatrix::CMatrix(int m, double *arr) {
	setMatrix(m, m, arr);
	id = ++count;
	printf("Constructor 2: Matrix %d\n\n", id);
}

CMatrix::CMatrix(int m, int n, double *arr) {
	setMatrix(m, n, arr);
	id = ++count;
	printf("Constructor 3: Matrix %d\n\n", id);
}

CMatrix::CMatrix(const CMatrix& m) {
	setMatrix(m.row, m.col, NULL);
	for (int i = 0; i < row; i++) {
		matrix[i] = new double[col];
		for (int j = 0; j < col; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}
	id = ++count;
	printf("Constructor 4: Matrix %d. Copy from %d to %d\n\n", id, m.id, id);
}

CMatrix::~CMatrix() {
	if (matrix) {
		for (int i = 0; i < row; i++) {
			delete[] matrix[i];
		}
		delete[]matrix;
	}
	printf("Destructor: Matrix %d destroyed!\n", id);
}

void CMatrix::setMatrix(int Row, int Col, double *arr) {
	if (Row < 0 || Col < 0) {
		throw Exception(1, id);
	}

	if (Row == 0 || Col == 0) {
		matrix = NULL;
		row = col = 0;
	}
	else {
		row = Row;
		col = Col;
		matrix = new double *[row];
	}
	for (int i = 0, val = 0; i < row; i++) {
		matrix[i] = new double[col];
		for (int j = 0; j < col; j++) {
			matrix[i][j] = (arr == NULL) ? 0.00 : arr[val];
			val++;
			if (val == 50)
				val = 0;
		}
	}
}

bool CMatrix::multest(const CMatrix& m) const {
//	return (m1.col == m2.row);

//	if (m.col > 1)
		return (col == m.row);
}

bool CMatrix::sumtest(const CMatrix& m) const {
	return(row == m.row && col == m.col);
}

double CMatrix::maxelem() const {
	if (row == 0 || col == 0) {
		throw Exception(2, id);
	}
	double max = matrix[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (max < matrix[i][j]) {
				max = matrix[i][j];
			}
		}
	}
	return max;
}

double CMatrix::minelem() const {
	if (row == 0 || col == 0) {
		throw Exception(2, id);
	}
	double min = matrix[0][0];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (min > matrix[i][j]) {
				min = matrix[i][j];
			}
		}
	}
	return min;
}

const double& CMatrix::operator()(int m, int n) const {
	check();
	if (m >= row || n >= col || m < 0 || n < 0)
		throw Exception(4, id);
	return matrix[m][n];
}

double& CMatrix::operator()(int m, int n) {
	check();
	if (m < row && n < col && m >= 0 && n >= 0)
		return matrix[m][n];
	throw Exception(4, id);
}

ostream& operator<<(ostream& out, const CMatrix& m) {
	streamsize width = out.width();
	for (int i = 0; i < m.row; i++) {
		for (int j = 0; j < m.col; j++) {
			out << setw(width) << m.matrix[i][j] << " ";
		}
		out << endl;
	}
	out << endl;
	return out;
}

CMatrix& CMatrix::operator=(const CMatrix &m) {
	if (!sumtest(m)) {
		if (matrix) {
			for (int i = 0; i < row; i++) {
				delete[] matrix[i];
			}
			delete[]matrix;
		}
		setMatrix(m.row, m.col, NULL);
	}
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] = m.matrix[i][j];
		}
	}

	return *this;
}

CMatrix& CMatrix::operator+=(const CMatrix& m) {
	if (sumtest(m)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] += m.matrix[i][j];
			}
		}
	}
	else
		throw Exception(3, m.id);

	return *this;
}

CMatrix& CMatrix::operator-=(const CMatrix& m) {
	if (sumtest(m)) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] -= m.matrix[i][j];
			}
		}
	}
	else
		throw Exception(3, m.id);

	return *this;
}

CMatrix& CMatrix::operator*=(const CMatrix& m) {
	check();
	if (multest(m)) {
		CMatrix tmp(row, m.col);
		int i, j, inner;
		for (i = 0; i < row; i++) {
			for (j = 0; j < m.col; j++) {
				for (inner = 0; inner < col; inner++) {
					tmp.matrix[i][j] += matrix[i][inner] * m.matrix[inner][j];
				}
			}
		}
		*this = tmp;
	}
	else
		throw Exception(3, m.id);

	return *this;
}

CMatrix& CMatrix::operator*=(double scalar) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			matrix[i][j] *= scalar;
		}
	}
	return *this;
}

CMatrix operator+(const CMatrix& m1, const CMatrix& m2) {
	CMatrix tmp(m1);
	tmp += m2;

	return tmp;
}

CMatrix operator-(const CMatrix& m1, const CMatrix& m2) {
	CMatrix tmp(m1);
	tmp -= m2;

	return tmp;
}

CMatrix operator*(const CMatrix& m1, const CMatrix& m2) {
	CMatrix tmp(m1);
	tmp *= m2;

	return tmp;
}

CMatrix operator*(const CMatrix& m, double scalar) {
	CMatrix tmp(m);
	tmp *= scalar;

	return tmp;
}

CMatrix operator*(double scalar, const CMatrix& m) {
	CMatrix tmp(m);
	tmp *= scalar;

	return tmp;
}

void CMatrix::check() const {

}

void CMatrix::check_v() const {
	if (col > 1)
		throw Exception(5, id);
}

int CMatrix::get_Row() const {
	return row;
}

int CMatrix::get_Col() const {
	check();
	return col;
}

char* CMatrix::Exception(int num, int ID) const {
	switch (num)
	{
	case 1:
		sprintf_s(msg, "Invalid input value: Matrix %d\n", id);
		break;
	case 2:
		sprintf_s(msg, "Can't find Max/Min: Matrix %d is NULL\n", id);
		break;
	case 3:
		sprintf_s(msg, "Invalid matrix size: Matrix %d and Matrix %d\n", id, ID);
		break;
	case 4:
		sprintf_s(msg, "Invalid index: Matrix %d\n", id);
		break;
	case 5:
		sprintf_s(msg, "This is Vector %d\n", id);
		break;
	case 6:
		sprintf_s(msg, "Error: Convert Matrix to Vector %d\n", id);
		break;
	}
	return msg;
}