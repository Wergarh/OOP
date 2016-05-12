#include <stdio.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include "CVector.h"

int CVector::count;

CVector::CVector() {
	X = 0.0;
	Y = 0.0;
	Z = 0.0;
	id = ++count;
	printf("Constructor 1: Vector %d\nX = %.1f;\nY = %.1f;\nZ = %.1f;\n\n", id, X, Y, Z);
}

CVector::CVector(double x, double y, double z) {
	X = x;
	Y = y;
	Z = z;
	id = ++count;
	printf("Constructor 2: Vector %d\nX = %.1f;\nY = %.1f;\nZ = %.1f;\n\n", id, X, Y, Z);
}

CVector::CVector(const CVector &v) {
	*this = v;
	id = ++count;
	printf("Constructor 3: Copy from %d to %d\n\n", v.id, id);
}

CVector::~CVector() {
	printf("Destructor: Vector %d destroyed!\n", id);
}

double CVector::get_X() const { return X; }

double CVector::get_Y() const { return Y; }

double CVector::get_Z() const { return Z; }

double CVector::set_X(double x) {
	X = x;
	return X;
}

double& CVector::set_X() {
	return X;
}

double CVector::set_Y(double y) {
	Y = y;
	return Y;
}

double CVector::set_Z(double z) {
	Z = z;
	return Z;
}

double CVector::modul() const {
	double res = sqrt(X*X + Y*Y + Z*Z);
	return res;
}

CVector& CVector::operator=(const CVector& v1) {
	X = v1.X;
	Y = v1.Y;
	Z = v1.Z;
	return *this;
}

CVector& CVector::operator*=(double scalar) {
	X *= scalar;
	Y *= scalar;
	Z *= scalar;
	return *this;
}

void CVector::normv() {
	int mod = modul();
	if (mod != 0) {

		X /= mod;
		Y /= mod;
		Z /= mod;
	}
	else { throw "divide by zero!"; }
}

void CVector::printv() const {
	printf("Vector %d: X = %.1f, Y = %.1f, Z = %.1f\n", id, X, Y, Z);
}

void CVector::copyVector(const CVector& v)
{
	X = v.X;
	Y = v.Y;
	Z = v.Z;
}

void CVector::copyTo(CVector& v) {
	v.copyVector(*this);
}

CVector operator+(const CVector &v1, const CVector &v2) {
	return CVector(v1.get_X() + v2.get_X(), v1.get_Y() + v2.get_Y(), v1.get_Z() + v2.get_Z());
}

CVector operator-(const CVector& v1, const CVector& v2) {
	return CVector(v1.get_X() - v2.get_X(), v1.get_Y() - v2.get_Y(), v1.get_Z() - v2.get_Z());
}

CVector operator*(const CVector& v1, const CVector& v2) {
	return CVector((v1.get_Y() * v2.get_Z()) - (v1.get_Z() * v2.get_Y()),
				   (v1.get_Z() * v2.get_X()) - (v1.get_X() * v2.get_Z()),
				   (v1.get_X() * v2.get_Y()) - (v1.get_Y() * v2.get_X()));
}

double mulscal(const CVector& v1, const CVector& v2) {
	double s = (v1.get_X() * v2.get_X()) + (v1.get_Y() * v2.get_Y()) + (v1.get_Z() * v2.get_Z());
	return s;
}

double cos(const CVector& v1, const CVector& v2) {
	double cosinus = (mulscal(v1, v2)) / (v1.modul() * v2.modul());
	return cosinus;
}

double sin(const CVector& v1, const CVector& v2) {
	double sinus = (v1 * v2).modul() / (v1.modul() * v2.modul());
	return sinus;
}

double angle(const CVector& v1, const CVector& v2) {
	double angl = (atan2(cos(v1, v2), sin(v1, v2))*180/M_PI);
	return angl;
}