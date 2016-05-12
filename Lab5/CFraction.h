#ifndef _CFRACTION_H_
#define _CFRACTION_H_

#include <iostream>

using std::ostream;

char msg2[100];

template <class T>
class CFraction {
private:
	T numerator, denominator;

public:
	CFraction() { numerator = 0; denominator = 1; }
	CFraction(const T &num) { numerator = num; denominator = 1; }
	CFraction(const T &num, const T &denom) {
		if (denom != 0) {
			numerator = num;
			denominator = denom;
			reduce();
		}
		else {
			throw Exception(1);
		}
	}

	~CFraction() {}

	const T& getNumerator() const { return numerator; }
	const T& getDenominator() const { return denominator; }

	friend ostream& operator<<(ostream& out, const CFraction<T>& f) {
		out << f.numerator << "/" << f.denominator << endl;

		return out;
	}

	friend CFraction<T>& operator+=(CFraction<T>& f1, const CFraction<T>& f2) {
		f1.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
		f1.denominator *= f2.denominator;
		f1.reduce();

		return f1;
	}

	friend CFraction<T>& operator-=(CFraction<T>& f1, const CFraction<T>& f2) {
		f1.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
		f1.denominator *= f2.denominator;
		f1.reduce();

		return f1;
	}

	friend CFraction<T>& operator*=(CFraction<T>&, const CFraction<T>&) {
		f1.numerator *= f2.numerator;
		f1.denominator *= f2.denominator;
		f1.reduce();

		return f1;
	}

	friend CFraction<T>& operator/=(CFraction<T>& f1, const CFraction<T>& f2) {
		f1.numerator *= f2.denominator;
		f1.denominator *= f2.numerator;
		f1.reduce();

		return f1;
	}

	friend CFraction<T> operator+(const CFraction<T>& f1, const CFraction<T>& f2) {
		CFraction<T> F(f1);

		return (F += f2);
	}

	friend CFraction<T> operator-(const CFraction<T>& f1, const CFraction<T>& f2) {
		CFraction<T> F(f1);

		return (F -= f2);
	}
	friend CFraction<T> operator*(const CFraction<T>& f1, const CFraction<T>& f2) {
		CFraction<T> F(f1);

		return 	(F *= f2);
	}

	friend CFraction<T> operator/(const CFraction<T>& f1, const CFraction<T>& f2) {
		CFraction<T> F(f1);

		return (F /= f2);
	}

	void reduce() {
		T a = 0;
		T b = 0;
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
		T gcd = a;
		numerator /= gcd;
		denominator /= gcd;
	}

	const T Decomp() {
		T val = numerator / denominator;
		numerator %= denominator;

		return val;
	}

	char* Exception(int num) const {
		switch (num)
		{
		case 1:
			sprintf_s(msg2, "Error: Division by zero!\n");
			break;
		}
		return msg2;
	}
};



#endif