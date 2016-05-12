#ifndef _CVECTOR_H_
#define _CVECTOR_H_

#include "CMatrix.h"

template <class T>
class CVector : public CMatrix<T> {
public:
	CVector() {}
	explicit CVector(int v, T*arr = NULL) : CMatrix(v, 1, arr){}
	CVector(const CVector<T>& v) : CMatrix(v) {}
	CVector(const CMatrix<T>& m) { *this = m; }
	~CVector() {}

	const T& operator()(int index) const {
		if (index >= row || index < 0)
			throw Exception(4);
		return matrix[index][0];
	}

	T& operator()(int index) {
		if (index >= row || index < 0)
			throw Exception(4);
		return matrix[index][0];
	}

	CVector& operator=(const CMatrix<T>& m) {
		m.check_v();
		CMatrix::operator=(m);

		return *this;
	}

	friend T operator*(const CVector<T>& v1, const CVector<T>& v2) {
		T sum = 0;
		if (v1.get_Row() == v2.get_Row()) {
			for (int i = 0; i < v1.get_Row(); i++)
				sum += v1(i) * v2(i);
		}
		return sum;
	}

protected:
	void check() const { throw Exception(5); }
};

#endif
