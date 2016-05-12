#include <stdio.h>
#include <iostream>
#include "CVector.h"
#include "CMatrix.h"
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

		char b[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j',
			'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
			'u', 'v', 'w', 'x', 'y', 'z'
		};

		CMatrix <double> matrx(5, a);
		CMatrix <double> matrx2(5, a);
		CMatrix<CMatrix<double>> matrx3(4);
		cout << matrx2.maxelem() << endl;
		matrx3.minelem();
		if (matrx == matrx2) cout << "Matrix: equal" << endl;
		CPolynomial polynm1(4, a), polynm2(4, a+6);
		cout << polynm1 << polynm2;
		if (polynm1 == polynm2) cout << "Polynomial: equal" << endl;



	}

	catch (char *msg) {
		cerr << msg;
	}

	return 0;
}