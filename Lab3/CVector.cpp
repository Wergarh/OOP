#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "CVector.h"

CVector::CVector() {
	//setMatrix(0, 0, NULL);
}

CVector::CVector(int v, double *arr) : CMatrix(v, 1, arr) {
	
	//setMatrix(v, 1, arr);
}

CVector::CVector(const CVector& v) : CMatrix(v) {
}

CVector::CVector(const CMatrix & m) {
	*this = m;
}

CVector::~CVector() {
	std::cout << "Vector destructor\n";
}

const double& CVector::operator()(int index) const {
	if (index >= row || index < 0)
		throw Exception(4, id);
	return matrix[index][0];
}

double& CVector::operator()(int index) {
	if (index >= row || index < 0)
		throw Exception(4, id);
	return matrix[index][0];
}

CVector& CVector::operator=(const CMatrix& m) {
	m.check_v();
	CMatrix::operator=(m);

	return *this;
}

double operator*(const CVector& v1, const CVector& v2) {
	double sum = 0;
	if (v1.get_Row() == v2.get_Row()) {
		for (int i = 0; i < v1.get_Row(); i++)
			sum += v1(i) * v2(i);
	}
	return sum;
}


void CVector::check() const {
		throw Exception(5, id);
}
