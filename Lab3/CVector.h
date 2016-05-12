#ifndef _CVECTOR_H_
#define _CVECTOR_H_
#include "CMatrix.h"

class CVector : public CMatrix {
public:
	CVector();
	explicit CVector(int v, double *arr = NULL);
	CVector(const CVector&);
	CVector(const CMatrix&);
	~CVector();

	const double& operator()(int index) const;
	double& operator()(int index);
	CVector& operator=(const CMatrix&);
protected:
	void check() const;
};

double operator*(const CVector&, const CVector&);

#endif
