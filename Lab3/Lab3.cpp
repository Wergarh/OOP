#include <stdio.h>
#include <stdlib.h>
#include "CMatrix.h"
#include "CVector.h"

#include <iostream>

using namespace std;

int main() {
	try {
		double a[50] = { 18.5, 7.7, 55.6, 61.8, 30.4,
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

		CVector V, V1(6, a), V2(6, a + 6);
		CMatrix M, M1(5, a), M2(5, a + 6);

		cout << V1 << V2 << M1;
	//	cout << ((CMatrix&)V1)(0, 0) << endl;
	//	cout << V1 << V2;
	}

	catch (char *msg) {
		cerr << msg;
	}

	return 0;
}