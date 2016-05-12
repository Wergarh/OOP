#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include "CMatrix.h"

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

		CMatrix mdefault, square(4, a), square2(4, a + 5), recta(5, 4, a + 10);

	//	cout << fixed << setw(8) << setprecision(2) << square << setw(8) << square2;

		
		//int *i = new int [10];
		//*i = 777;
		//delete i;
		
	//	square = square2;
		//recta = 2;
		cout << fixed << setw(8) << setprecision(2) << 4*square;

		//cout << square << square2 << recta;

		//	recta.maxelem();
		//	square.minelem();
		//	mdefault = square + square;
		//	cout << mdefault;
		//	square(1, 2) = 6.6;
		//	cout << square;
		//	mdefault = square;
		//	cout << scientific << mdefault;
		//	square += square;
		//	square -= square;
		//	square *= square;
		//	square *= 3;
		//	square + square;
		//	square - square;
		//	square * square;
		//	square * 2;
	}
	
	catch (const char *msg) {
		cerr << msg;
	}
	
	return 0;
}