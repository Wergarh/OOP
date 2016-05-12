#ifndef _CMATRIX_H_
#define _CMATRIX_H_

#include <iostream>

using std::ostream;

class CMatrix {
	double **matrix;
	int row, col, id;
	static int count;
	void setMatrix(int row, int col, double *arr);

public:
	CMatrix();
	CMatrix(double a);
	explicit CMatrix(int n, double *arr = NULL);
	CMatrix(int m, int n, double *arr = NULL);
	CMatrix(const CMatrix&);
	~CMatrix();

	static bool multest(const CMatrix&, const CMatrix&);

	bool sumtest(const CMatrix&) const;
	double maxelem() const;
	double minelem() const;

	const char* Exception(int, int = -1) const;

	const double& operator()(int m, int n) const;
	double& operator()(int m, int n);
	friend ostream& operator<<(ostream&, const CMatrix&);
	CMatrix& operator=(const CMatrix&);
	CMatrix& operator+=(const CMatrix&);
	CMatrix& operator-=(const CMatrix&);
	CMatrix& operator*=(const CMatrix&);
	CMatrix& operator*=(double);
};

CMatrix operator+(const CMatrix&, const CMatrix&);
CMatrix operator-(const CMatrix&, const CMatrix&);
CMatrix operator*(const CMatrix&, const CMatrix&);
CMatrix operator*(const CMatrix&, double);
CMatrix operator*(double, const CMatrix&);

#endif 