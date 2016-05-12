#include <stdio.h>
#include <iostream>
#include "CFraction.h"
#include "CPolynomial.h"

using namespace std;

int main() {
	try {
		double a[] = { 18.5, 7.7, 55.6, 61.8, 30.4,
			33.7, 79.3, 29.9, 9.5, 20.9,
			27.7, 80.3, 61.5, 20.0, 73.4,
			12.4, 77.6, 63.1, 76.3, 51.2,
			1.4, 10.3, 68.3, 26.8, 15.0,
			53.2, 14.4, 19.7, 87.9, 84.6,
			60.2, 84.4, 92.7, 100.9, 14.4,
			65.5, 76.6, 27.8, 81.1, 28.8,
			58.6, 30.3, 89.8, 1.9, 3.0,
			55.4, 60.7, 95.2, 97.6, 12.6
		};

		CFraction A(6, 9), B(4, 12), C = 5;
//		cout << A << B << endl;
		C = A / B;
//		cout << C;
		C.Decomp();
//		cout << C;

		CPolynomial P1(3, a), P2(2, a + 3), P3;
	//	P3 = P1 / P2;
	//	cout << P1 << P2 << P3;
		cout << "P1: " << P1 << "P2: " << P2;
	//	P1 = P1 * 2;
		P2 -= P1;
		cout << "P2 - P1 = " << P2;
	}

	catch (char *msg) {
		cerr << msg;
	}

	return 0;
}