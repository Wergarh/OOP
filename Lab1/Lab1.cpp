#include <stdio.h>
#include "CVector.h"

int main() {
	CVector A(4.5, 6.3, 7.4), B(3.6, 2.4, 5.8), C;
//	int q = A.set_X();
//	printf("%d\n", q);
//	A.set_X() = 5;
	A.printv();
	B.printv();

/*	A.modul();
	C = A;
	A*=4.3;
	A.printv();
	A.normv();
	A + B;
	A - B;
	A * B;
	mulscal(A, B);
	cos(A, B);
	sin(A, B);
	angle(A, B);
	C.printv();
*/	
//	C.operator = (operator + (A, B));
	A.copyTo(B);
	A.printv();
	B.printv();
//	C.normv();
//	printf("%g\n", C.modul());
//	printf("%g\n", sin(A, B));

	return 0;
}