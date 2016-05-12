#include "CFraction.h"

using namespace std;

char msg2[100];

CFraction::CFraction() {
	numerator = 0;
	denominator = 1;
}

CFraction::CFraction(int num) {
	numerator = num;
	denominator = 1;
}

CFraction::CFraction(int num, int denom) {
	if (denom != 0) {
		numerator = num;
		denominator = denom;
		reduce();
	}
	else {
		throw Exception(1);
	}
}
/*
CFraction::CFraction(const CFraction& f) {
	numerator = f.numerator;
	denominator = f.denominator;
}*/

CFraction::~CFraction() {

}

int CFraction::getNumerator() const {
	return numerator;
}
int CFraction::getDenominator() const {
	return denominator;
}

ostream& operator<<(ostream& out, const CFraction& f) {
	out << f.numerator << "/" << f.denominator << endl;

	return out;
}

CFraction& operator+=(CFraction& f1, const CFraction& f2) {
	f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
	f1.denominator *= f2.denominator;
	f1.reduce();

	return f1;
}

CFraction& operator-=(CFraction& f1, const CFraction& f2) {
	f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
	f1.denominator *= f2.denominator;
	f1.reduce();

	return f1;
}

CFraction& operator*=(CFraction& f1, const CFraction& f2) {
	f1.numerator *= f2.numerator;
	f1.denominator *= f2.denominator;
	f1.reduce();

	return f1;
}

CFraction& operator/=(CFraction& f1, const CFraction& f2) {
	f1.numerator *= f2.denominator;
	f1.denominator *= f2.numerator;
	f1.reduce();

	return f1;
}

CFraction operator+(const CFraction& f1, const CFraction& f2) {
	CFraction F(f1);
	
	return (F += f2);
}

CFraction operator-(const CFraction& f1, const CFraction& f2) {
	CFraction F(f1);

	return (F -= f2);
}

CFraction operator*(const CFraction& f1, const CFraction& f2) {
	CFraction F(f1);

	return 	(F *= f2);
}

CFraction operator/(const CFraction& f1, const CFraction& f2) {
	CFraction F(f1);

	return (F /= f2);
}

void CFraction::reduce() {
	int a = 0;
	int b = 0;
	if (denominator < 0) {
		numerator *= -1;
		denominator *= -1;
	}
	if (numerator < 2) return;
	a = numerator;
	b = denominator;
	while (a != b) {
		if (a > b)
			a -= b;
		else b -= a;
	}
	int gcd = a;
	numerator /= gcd;
	denominator /= gcd;
}

int CFraction::Decomp() {
	int val = numerator / denominator;
	numerator %= denominator;

	return val;
}

char* CFraction::Exception(int num) const {
	switch (num)
	{
	case 1:
		sprintf_s(msg2, "Error: Division by zero!\n");
		break;
	}
	return msg2;
}