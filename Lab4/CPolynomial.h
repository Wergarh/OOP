#ifndef _CPOLYNOMIAL_H_
#define _CPOLYNOMIAL_H_

#include <iostream>
#include <iomanip>

using std::ostream;

class CPolynomial {
private:
	unsigned int deg;
	double *coef;

public:
	CPolynomial();
	explicit CPolynomial(unsigned int, double *arr = NULL);
	CPolynomial(const CPolynomial&);
	~CPolynomial();

	void setPolynomial(unsigned int, double *arr);
	void correctDeg();
	double operator[](unsigned int) const;
	double& operator[](unsigned int);
	CPolynomial& operator=(const CPolynomial&);
	friend ostream& operator<<(ostream&, const CPolynomial&);
	friend CPolynomial& operator+=(CPolynomial&, const CPolynomial&);
	friend CPolynomial& operator-=(CPolynomial&, const CPolynomial&);
	friend CPolynomial& operator*=(CPolynomial&, const CPolynomial&);
	friend CPolynomial operator+(const CPolynomial&, const CPolynomial&);
	friend CPolynomial operator-(const CPolynomial&, const CPolynomial&);
	friend CPolynomial operator*(const CPolynomial&, const CPolynomial&);
	friend CPolynomial& operator%=(CPolynomial&, const CPolynomial&);
	friend CPolynomial operator%(const CPolynomial&, const CPolynomial&);
	friend CPolynomial& operator/=(CPolynomial&, const CPolynomial&);
	friend CPolynomial operator/(const CPolynomial&, const CPolynomial &);
	friend CPolynomial& operator*=(CPolynomial&, double);
	friend CPolynomial operator*(const CPolynomial&, double);
	friend CPolynomial operator*(double, const CPolynomial&);
	friend CPolynomial Mult(double, const CPolynomial&);
	double operator() (double);

	char* Exception(int) const;
};

#endif