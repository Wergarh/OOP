#ifndef _CFRACTION_H_
#define _CFRACTION_H_

#include <iostream>
#include <iomanip>

using std::ostream;

class CFraction {
private:
	int numerator, denominator;

public:
	CFraction();
	CFraction(int num);
	CFraction(int num, int denom);
	~CFraction();

	int getNumerator() const;
	int getDenominator() const;

	friend ostream& operator<<(ostream&, const CFraction&);
	friend CFraction& operator+=(CFraction&, const CFraction&);
	friend CFraction& operator-=(CFraction&, const CFraction&);
	friend CFraction& operator*=(CFraction&, const CFraction&);
	friend CFraction& operator/=(CFraction&, const CFraction&);
	friend CFraction operator+(const CFraction&, const CFraction&);
	friend CFraction operator-(const CFraction&, const CFraction&);
	friend CFraction operator*(const CFraction&, const CFraction&);
	friend CFraction operator/(const CFraction&, const CFraction&);

	void reduce();
	int Decomp();

	char* Exception(int) const;
};



#endif