#ifndef _CMATRIX_H_
#define _CMATRIX_H_

#include <iostream>

using std::ostream;

class CMatrix {
protected:
	double **matrix;
	int row, col, id;
	static int count;
	void setMatrix(int row, int col, double *arr);

public:
	CMatrix();
	explicit CMatrix(int n, double *arr = NULL);
	CMatrix(int m, int n, double *arr = NULL);
	CMatrix(const CMatrix&);
	virtual ~CMatrix();

	bool multest(const CMatrix&) const;
	bool sumtest(const CMatrix&) const;
	double maxelem() const;
	double minelem() const;

	char* Exception(int, int = -1) const;

	const double& operator()(int m, int n) const;
	double& operator()(int m, int n);
	friend ostream& operator<<(ostream&, const CMatrix&);
	virtual CMatrix& operator=(const CMatrix&);
	CMatrix& operator+=(const CMatrix&);
	CMatrix& operator-=(const CMatrix&);
	CMatrix& operator*=(const CMatrix&);
	CMatrix& operator*=(double);

	virtual void check() const;
	virtual void check_v() const;
	int get_Row() const;
	int get_Col() const;
};

CMatrix operator+(const CMatrix&, const CMatrix&);
CMatrix operator-(const CMatrix&, const CMatrix&);
CMatrix operator*(const CMatrix&, const CMatrix&);
CMatrix operator*(const CMatrix&, double);
CMatrix operator*(double, const CMatrix&);

#endif 