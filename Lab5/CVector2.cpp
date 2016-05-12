//#include "CVector.h"

template <class T>
CVector<T>::CVector() {
	//setMatrix(0, 0, NULL);
}

template <class T>
CVector<T>::CVector(int v, const T*arr) : CMatrix(v, 1, arr) {
	//setMatrix(v, 1, arr);
}

template <class T>
CVector<T>::CVector(const CVector<T>& v) : CMatrix(v) {
}

template <class T>
CVector<T>::CVector(const CMatrix<T>& m) {
	*this = m;
}

template <class T>
CVector<T>::~CVector() {
	std::cout << "Vector destructor\n";
}

template <class T>
const T& CVector<T>::operator()(int index) const {
	if (index >= row || index < 0)
		throw Exception(4);
	return matrix[index][0];
}

template <class T>
T& CVector<T>::operator()(int index) {
	if (index >= row || index < 0)
		throw Exception(4);
	return matrix[index][0];
}

template <class T>
CVector<T>& CVector<T>::operator=(const CMatrix<T>& m) {
	m.check_v();
	CMatrix::operator=(m);

	return *this;
}

template <class T>
T operator*(const CVector<T>& v1, const CVector<T>& v2) {
	T sum = 0;
	if (v1.get_Row() == v2.get_Row()) {
		for (int i = 0; i < v1.get_Row(); i++)
			sum += v1(i) * v2(i);
	}
	return sum;
}

template <class T>
void CVector<T>::check() const {
	throw Exception(5);
}
