#include "CPolynomial.h"

using namespace std;

char msg[100];

CPolynomial::CPolynomial() {
	setPolynomial(0, NULL);
}

CPolynomial::CPolynomial(unsigned int newDeg, double* newCoef) {
	setPolynomial(newDeg, newCoef);
}

CPolynomial::CPolynomial(const CPolynomial& p) {
	setPolynomial(p.deg - 1, p.coef);
}

CPolynomial::~CPolynomial() {
	delete[] coef;
}

void CPolynomial::setPolynomial(unsigned int degree, double *arr) {
	deg = degree + 1;
	coef = new double[deg];
	for (unsigned int i = 0; i < deg; i++) {
		coef[i] = arr ? arr[i] : 0.0;
	}
}

void CPolynomial::correctDeg() {
	if (coef[deg] == 0) {
		do {
			deg--;
		} while (deg && coef[deg] == 0);
	}
}

double CPolynomial::operator[](unsigned int i) const {
	if (i < deg) {
		return coef[i];
	}
	else {
		throw Exception(1);
	}
}

double& CPolynomial::operator[](unsigned int i) {
	if (i < deg) {
		return coef[i];
	}
	else {
		throw Exception(1);
	}
}

CPolynomial& CPolynomial::operator=(const CPolynomial& p) {
	if (deg == p.deg)
		for (unsigned int i = 0; i < deg; i++)
			coef[i] = p.coef[i];
	else {
		if (coef != NULL)
			delete[] coef;
		setPolynomial(p.deg - 1, p.coef);
	}

	return *this;
}

ostream& operator<<(ostream& out, const CPolynomial& p) {
	for (int i = p.deg - 1; i > 0; i--) {
		if (p.coef[i] > 0) {
			if (p.coef[i] == 1)
				out << " + X^" << i;
			else
				out << " + " << p.coef[i] << "X^" << i;
		}
		else if (p.coef[i] < 0)
			if (p.coef[i] == -1)
				out << " - X^" << i;
			else
				out << " - " << (-1) * p.coef[i] << "X^" << i;
	}

	if (p.coef[0] > 0)
		out << " + " << p.coef[0] << "\n";
	else if (p.coef[0] < 0)
		out << " - " << (-1) * p.coef[0] << "\n";

	return out;
}

CPolynomial& operator+=(CPolynomial& p1, const CPolynomial& p2) {
	if (p1.deg >= p2.deg) {
		for (unsigned int i = 0; i <= p2.deg; i++) {
			p1.coef[i] += p2.coef[i];
		}
	}
	else {
		unsigned int i = 0;
		double *result = new double[p2.deg];
		for (; i < p1.deg; i++) {
			result[i] = p1.coef[i] + p2.coef[i];
		}
		for (; i < p2.deg; i++) {
			result[i] = 0 + p2.coef[i];
		}
		delete[] p1.coef;
		p1.coef = result;
		p1.deg = p2.deg;
	}
	p1.correctDeg();

	return p1;
}

CPolynomial& operator-=(CPolynomial& p1, const CPolynomial& p2) {
	if (p1.deg >= p2.deg) {
		for (unsigned int i = 0; i <= p2.deg; i++) {
			p1.coef[i] -= p2.coef[i];
		}
	}
	else {
		unsigned int i = 0;
		double *result = new double[p2.deg];
		for (; i < p1.deg; i++) {
			result[i] = p1.coef[i] - p2.coef[i];
		}
		for (; i < p2.deg; i++) {
			result[i] = 0 - p2.coef[i];
		}
		delete[] p1.coef;
		p1.coef = result;
		p1.deg = p2.deg;
	}
	p1.correctDeg();

	return p1;
}

CPolynomial& operator*=(CPolynomial& p1, const CPolynomial& p2) {
	if (p1.deg == 0 || p2.deg == 0) {
		if (!p1.coef) delete[] p1.coef;
		p1.coef = NULL;
		p1.deg = 0;
	}
	else {
		CPolynomial result(p2.deg + p1.deg - 1);
		for (unsigned int i = 0; i < p2.deg; i++) {
			for (unsigned int j = 0; j < p1.deg; j++) {
				result[i + j] += p1.coef[j] * p2.coef[i];
			}
		}
		p1 = result;
	}

	return p1;
}

CPolynomial operator+(const CPolynomial& p1, const CPolynomial& p2) {
	CPolynomial P(p1);
	P += p2;

	return P;
}

CPolynomial operator-(const CPolynomial& p1, const CPolynomial& p2) {
	CPolynomial P(p1);
	P -= p2;

	return P;
}

CPolynomial operator*(const CPolynomial& p1, const CPolynomial& p2) {
	CPolynomial P(p1);
	P *= p2;

	return P;
}

CPolynomial& operator%=(CPolynomial& p1, const CPolynomial& p2) {
	unsigned int pDeg = p1.deg - 1;
	unsigned int rDeg = p1.deg - p2.deg;
	while (pDeg >= p2.deg - 1) {
		double res = p1[pDeg] / p2[p2.deg - 1];
		for (int i = p2.deg - 1; i >= 0; i--)
			p1[i + rDeg] -= res * p2[i];
		pDeg--;
		rDeg--;
	}
	p1.correctDeg();

	return p1;
}

CPolynomial operator%(const CPolynomial& p1, const CPolynomial& p2) {
	CPolynomial P(p1);
	P %= p2;

	return P;
}

CPolynomial& operator/=(CPolynomial& p1, const CPolynomial& p2) {
	CPolynomial res(p1.deg - p2.deg);
	unsigned int pDeg = p1.deg - 1;
	unsigned int rDeg = res.deg - 1;
	while (pDeg >= p2.deg - 1) {
		res[rDeg] = p1[pDeg] / p2[p2.deg - 1];
		for (int i = p2.deg - 1; i >= 0; i--)
			p1[i + rDeg] -= res[rDeg] * p2[i];
		pDeg--;
		rDeg--;
	}
	p1 = res;
	p1.correctDeg();

	return p1;
}

CPolynomial operator/(const CPolynomial& p1, const CPolynomial& p2) {
	CPolynomial P(p1);
	P /= p2;

	return P;
}

CPolynomial& operator*=(CPolynomial& p, double a) {
	return p = Mult(a, p);
}

CPolynomial operator*(const CPolynomial& p, double a) {
	return Mult(a, p);
}

CPolynomial operator*(double a, const CPolynomial& p) {
	return Mult(a, p);
	//return CPolynomial(p) *= a;
}

CPolynomial Mult(double a, const CPolynomial & p) {
	if (a == 0) {
		CPolynomial result;

		return result;
	}
	else {
		int deg = p.deg;
		double *tmp_koef = new double [deg];
		for (unsigned int i = 0; i < p.deg; i++)
			tmp_koef[i] = a * p.coef[i];
		CPolynomial result(deg - 1, tmp_koef);
		delete[] tmp_koef;

		return result;
	}
}

double CPolynomial::operator()(double v) {
	double result = 0;

	for (unsigned int i = 0; i < deg; i++) {
		result += coef[i] * pow(v, i);
	}

	return result;
}

char* CPolynomial::Exception(int num) const {
	switch (num)
	{
	case 1:
		sprintf_s(msg, "Error: Invalid index!\n");
		break;
	}
	return msg;
}