#ifndef _CVECTOR_H_
#define _CVECTOR_H_

class CVector {
	double X, Y, Z;
	int id;
	static int count;

public:
	CVector();
	CVector(double x, double y, double z);
	CVector(const CVector&);
	~CVector();

	double get_X() const;
	double get_Y() const;
	double get_Z() const;
	double set_X(double x);
	double& set_X();
	double set_Y(double y);
	double set_Z(double z);
	double modul() const;
	CVector& operator=(const CVector&);
	CVector& operator*=(double);
	void normv();
	void printv() const;
	void copyVector(const CVector&);
	void copyTo(CVector&);
};

CVector operator+(const CVector&, const CVector&);
CVector operator-(const CVector&, const CVector&);
CVector operator*(const CVector&, const CVector&);
double mulscal(const CVector&, const CVector&);
double cos(const CVector&, const CVector&);
double sin(const CVector&, const CVector&);
double angle(const CVector&, const CVector&);

#endif
