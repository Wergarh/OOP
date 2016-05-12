#ifndef _CMATRIX_H_
#define _CMATRIX_H_

#include <iostream>
#include <iomanip>

using std::ostream;

template <class T>
class CMatrix {
protected:
	T **matrix;
	int row, col;
	void setMatrix(int Row, int Col, T *arr) {
		if (Row < 0 || Col < 0) {
			throw Exception(1);
		}

		if (Row == 0 || Col == 0) {
			matrix = NULL;
			row = col = 0;
		}
		else {
			row = Row;
			col = Col;
			matrix = new T*[row];
		}
		for (int i = 0, val = 0; i < row; i++) {
			matrix[i] = new T[col];
			for (int j = 0; j < col; j++) {
				matrix[i][j] = (arr == NULL) ? T() : arr[val];
				val++;
				if (val == 50)
					val = 0;
			}
		}
	}

public:
	CMatrix() { setMatrix(0, 0, NULL); }
	explicit CMatrix(int m, T *arr = NULL) { setMatrix(m, m, arr); }
	CMatrix(int m, int n, T *arr = NULL) { setMatrix(m, n, arr); }
	CMatrix(const CMatrix<T>& m) {
		setMatrix(m.row, m.col, NULL);
		for (int i = 0; i < row; i++) {
			matrix[i] = new T[col];
			for (int j = 0; j < col; j++) {
				matrix[i][j] = m.matrix[i][j];
			}
		}
	}

	virtual ~CMatrix() {
		if (matrix) {
			for (int i = 0; i < row; i++) {
				delete[] matrix[i];
			}
			delete[]matrix;
		}
	}

	bool multest(const CMatrix<T>& m) const { return (col == m.row); }
	bool sumtest(const CMatrix<T>& m) const { return(row == m.row && col == m.col); }

	const T &maxelem() const {
		if (row == 0 || col == 0) {
			throw Exception(2);
		}
		T &max = matrix[0][0];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (max < matrix[i][j]) {
					max = matrix[i][j];
				}
			}
		}
		return max;
	}

	const T &minelem() const {
		if (row == 0 || col == 0) {
			throw Exception(2);
		}
		T &min = matrix[0][0];
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				if (min > matrix[i][j]) {
					min = matrix[i][j];
				}
			}
		}
		return min;
	}

	const T& operator()(int m, int n) const {
		check();
		if (m >= row || n >= col || m < 0 || n < 0)
			throw Exception(4);
		return matrix[m][n];
	}

	T& operator()(int m, int n) {
		check();
		if (m < row && n < col && m >= 0 && n >= 0)
			return matrix[m][n];
		throw Exception(4);
	}

	friend ostream& operator<<(ostream& out, const CMatrix<T>& m) {
		streamsize width = out.width();
		for (int i = 0; i < m.row; i++) {
			for (int j = 0; j < m.col; j++) {
				out << setw(width) << m.matrix[i][j] << " ";
			}
			out << endl;
		}
		out << endl;
		return out;
	}

	virtual CMatrix<T>& operator=(const CMatrix<T>& m) {
		if (!sumtest(m)) {
			if (matrix) {
				for (int i = 0; i < row; i++) {
					delete[] matrix[i];
				}
				delete[]matrix;
			}
			setMatrix(m.row, m.col, NULL);
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] = m.matrix[i][j];
			}
		}

		return *this;
	}

	CMatrix<T>& operator+=(const CMatrix<T>& m) {
		if (sumtest(m)) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					matrix[i][j] += m.matrix[i][j];
				}
			}
		}
		else
			throw Exception(3);

		return *this;
	}

	CMatrix<T>& operator-=(const CMatrix<T>& m) {
		if (sumtest(m)) {
			for (int i = 0; i < row; i++) {
				for (int j = 0; j < col; j++) {
					matrix[i][j] -= m.matrix[i][j];
				}
			}
		}
		else
			throw Exception(3);

		return *this;
	}

	CMatrix<T>& operator*=(const CMatrix<T>& m) {
		check();
		if (multest(m)) {
			CMatrix tmp(row, m.col);
			int i, j, inner;
			for (i = 0; i < row; i++) {
				for (j = 0; j < m.col; j++) {
					for (inner = 0; inner < col; inner++) {
						tmp.matrix[i][j] += matrix[i][inner] * m.matrix[inner][j];
					}
				}
			}
			*this = tmp;
		}
		else
			throw Exception(3);

		return *this;
	}

	CMatrix<T>& operator*=(const T& scalar) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < col; j++) {
				matrix[i][j] *= scalar;
			}
		}
		return *this;
	}

	friend CMatrix<T> operator+(const CMatrix<T>& m1, const CMatrix<T>& m2) {
		CMatrix<T> tmp(m1);
		tmp += m2;

		return tmp;
	}

	friend CMatrix<T> operator-(const CMatrix<T>& m1, const CMatrix<T>& m2) {
		CMatrix<T> tmp(m1);
		tmp -= m2;

		return tmp;
	}

	friend CMatrix<T> operator*(const CMatrix<T>& m1, const CMatrix<T>& m2) {
		CMatrix<T> tmp(m1);
		tmp *= m2;

		return tmp;
	}

	friend CMatrix<T> operator*(const CMatrix<T>& m, const T& scalar) {
		CMatrix<T> tmp(m);
		tmp *= scalar;

		return tmp;
	}
	friend CMatrix<T> operator*(const T& scalar, const CMatrix<T>& m) {
		CMatrix<T> tmp(m);
		tmp *= scalar;

		return tmp;
	}

	bool operator==(const CMatrix<T>& m) const {
		return (row == m.row && col == m.col);
	}

	bool operator>(const CMatrix<T>& m) const {
		return (row * col) > (m.row * m.col);
	}

	bool operator<(const CMatrix<T>& m) const {
		return (row * col) < (m.row * m.col);
	}



	virtual void check() const {}
	virtual void check_v() const {
		if (col > 1)
			throw Exception(5);
	}

	int get_Row() const { return row; }
	int get_Col() const { check(); return col; }

	char* Exception(int num) const {
		switch (num)
		{
		case 1:
			return "Invalid input value";
			break;
		case 2:
			return "Can't find Max/Min: Matrix is NULL\n";
			break;
		case 3:
			return "Invalid matrix size\n";
			break;
		case 4:
			return "Invalid index\n";
			break;
		case 5:
			return "This is Vector\n";
			break;
		case 6:
			return "Error: Convert Matrix to Vector\n";
			break;
		}
		return NULL;
	}
};

#endif 