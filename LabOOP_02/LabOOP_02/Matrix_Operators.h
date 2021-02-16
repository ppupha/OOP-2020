#pragma once
#ifndef _MATRIX_OPERATORS_H_
#define _MATRIX_OPERATORS_H_

template<class T> bool Matrix<T>::operator == (const Matrix<T> &matrix) const
{
	if (!this->isSizeEqual(matrix))
		return false;

	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->col; j++)
			if (this->mat[i][j] != matrix.mat[i][j])
				return false;
	return true;
}

template<class T> bool Matrix<T>::operator != (const Matrix<T> &matrix) const
{
	return !(this->operator==(matrix));
}

template<class T> Matrix<T> Matrix<T>::operator - (const Matrix<T> &matrix) const
{
	if (!this->isSizeEqual(matrix))
		throw(ErrorSize("operator '-'", "Matrix", "Cant sub 2 matrix with diff size"));

	Matrix<T> res(matrix);

	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->col; j++)
		{
			res[i][j] = (*this)[i][j] - res[i][j];
		}

	return res;
}

template<class T> void Matrix<T>::operator-=(const Matrix<T> &matrix)
{
	if (!this->isSizeEqual(matrix))
		throw(ErrorSize("operator '-='", "Matrix", "Cant add 2 matrix with diff size"));
	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->getCol(); j++)
		{
			(*this)[i][j] -= matrix[i][j];
		}
}

template<class T> Matrix<T> Matrix<T>::operator + (const Matrix<T> &matrix) const
{
	if (!this->isSizeEqual(matrix))
		throw(ErrorSize("operator '+'", "Matrix", "Cant add 2 matrix with diff size"));

	Matrix<T> res(matrix);
	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->getCol(); j++)
		{
			res[i][j] += (*this)[i][j];
		}

	return res;
}

template<class T> void Matrix<T>::operator+=(const Matrix<T> &matrix)
{
	if (!this->isSizeEqual(matrix))
		throw(ErrorSize("operator '+='", "Matrix", "Cant add 2 matrix with diff size"));
	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->getCol(); j++)
		{
			(*this)[i][j] += matrix[i][j];
		}
}

template<class T> Matrix<T> Matrix<T>::operator * (const T& value) const
{
	Matrix<T> res(*this);
	for (size_t i = 0; i < res.getRow(); i++)
		for (size_t j = 0; j < res.getCol(); j++)
			res[i][j] *= value;
	return res;
}

template<class T> Matrix<T> operator*(const T& value, const Matrix<T>& matrix)
{
	return matrix * value;
}

template<class T> void Matrix<T>::operator *= (const T& value)
{
	Matrix<T> res = (*this) * value;
	(*this) = res;
}



template<class T> Matrix<T> Matrix<T>::operator * (const Matrix<T>& matrix) const
{
	if (this->getCol() != matrix.getRow())
		throw(ErrorMult("Operator '*'", "Matrix", "Cant mult 2 matrix"));

	Matrix<T> res(this->getRow(), matrix.getCol());

	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < matrix.getCol(); j++)
		{
			T s{};
			for (size_t k = 0; k < this->getCol(); k++)
				s += (*this)[i][k] * matrix[k][j];
			res[i][j] = s;
		}

	return res;
}

template<class T> void Matrix<T>::operator *= (const Matrix<T>& matrix)
{
	if (this->getCol() != matrix.getRow())
		throw(ErrorMult("Operator '*'", "Matrix", "Cant mult 2 matrix"));

	Matrix<T> res = (*this) * matrix;
	(*this) = res;
}



template<class T> const Array<T> Matrix<T>::operator [] (const size_t rowindex) const
{
	if (rowindex >= this->getRow())
		throw(ErrorIndex("Operator '[]'", "Matrix", "Index Out of Range"));

	const Array<T> res(this->mat[rowindex], this->col);
	return res;
}

template<class T> Array<T> Matrix<T>::operator [](const size_t rowindex)
{
	if (rowindex >= this->getRow())
		throw(ErrorIndex("Operator '[]'", "Matrix", "Index Out of Range"));

	Array<T> res(this->mat[rowindex], this->getCol());
	return res;
}

template<class T> istream& operator >> (istream& is, Matrix<T>& matrix)
{
	for (size_t i = 0; i < matrix.getRow(); i++)
		for (size_t j = 0; j < matrix.getCol(); j++)
			cin >> matrix[i][j];
	return is;

}

template<class T> ostream& operator << (ostream& os, Matrix<T>& matrix)
{
	if (matrix.isEmpty())
		throw(ErrorSize("Operator '<<'", "Matrix", "Cant output Empty Matrix"));

	for (size_t i = 0; i < matrix.getRow(); i++)
	{
		for (size_t j = 0; j < matrix.getCol(); j++)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}

	cout << endl;
	return os;
}

template<class T> ostream& operator << (ostream& os, const Matrix<T>& matrix)
{
	if (matrix.isEmpty())
		throw(ErrorSize("Operator '<<'", "Matrix", "Cant output Empty Matrix"));

	for (size_t i = 0; i < matrix.getRow(); i++)
	{
		for (size_t j = 0; j < matrix.getCol(); j++)
			cout << matrix[i][j] << "  ";
		cout << endl;
	}

	cout << endl;
	return os;
}

template<class T> Matrix<T>& Matrix<T>::operator = (const Matrix<T>& matrix)
{
	if (matrix.isEmpty())
		throw(ErrorSize("Operator '='", "Matrix", "Empty Matrix"));

	if (this == &matrix)
		return *this;
	//this->free();
	this->copy(matrix);

	return *this;
}

template<class T> Matrix<T>& Matrix<T>::operator =(Matrix<T> && matrix)
{
	//this->free();
	this->move(matrix);
	return *this;

}

template<class T> Matrix<T> Matrix<T>::operator ~() const
{
	if (this->isEmpty())
		throw(ErrorEmpty("Operator ~", "Matrix T", "Transpose Empty Matrix"));

	size_t col = this->getRow();
	size_t row = this->getCol();
	Matrix<T> tmp(row, col);
	for (size_t i = 0; i < row; i++)
		for (size_t j = 0; j < col; j++)
			tmp[i][j] = (*this)[j][i];
	return tmp;
}


template<class T> Matrix<T> Matrix<T>::conv() const
{
	if (!this->isSquare())
		throw(ErrorSize("conv", "Matrix", "Not Square Matrix"));
	T det = this->det();
	if (det == 0)
		throw(ErrorZeroDet("operator ^", "Matrix", "Zero Det"));

	size_t n = this->getRow();
	T zero{};
	T one = ++zero;
	zero--;
	T temp{};
	Matrix <T> a(*this);

	Matrix<T> b(n, n, 0);
	size_t i = 0, j = 0, k = 0;

	for (i = 0; i < n; i++) // Tạo ra b là ma trận đơn vị đó
		for (j = 0; j < n; j++)
			if (i == j) b[i][j] = one; else b[i][j] = zero;

	for (i = 0; i < n; i++) // Xử lý từ hàng đầu đến hàng cuối
	{
		if (a[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì đổi hàng
		{
			k = i + 1;
			while (k < n && a[k][i] == 0) k++;
			for (j = 0; j < n; j++) // Đổi hàng đó của a đó, cả với ma trận b nữa
			{
				temp = a[i][j];
				a[i][j] = a[k][j];
				a[k][j] = temp;
				temp = b[i][j];
				b[i][j] = b[k][j];
				b[k][j] = temp;
			}
		}

		temp = a[i][i];
		for (j = i; j < n; j++) a[i][j] /= temp;
		for (j = 0; j < n; j++) b[i][j] /= temp;

		for (j = i + 1; j < n; j++)
		{
			temp = -a[j][i];
			for (k = i; k < n; k++) a[j][k] += temp*a[i][k];
			for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
		}
	}// Kết thúc quá trình Gauss

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = 0; j < n; j++)
			cout << b[i][j] << "  ";
		cout << endl;
	}

	for (int i = n - 1; i > 0; i--) // Bắt đầu quá trình Jordan
	{
		cout << i << "   " << endl;;
		for (int j = i - 1; j >= 0; j--)
		{
			temp = -a[j][i];

			for (int k = n - 1; k >= i; k--)
				a[j][k] += temp*a[i][k];
			for (k = 0; k < n; k++)
				b[j][k] += temp*b[i][k];
		}
	}

	
	
	
	return b;
}

template<class T> Matrix<T> Matrix<T>::operator ^(const int pow) const
{
	if (!this->isSquare())
		throw(ErrorSize("operator ^", "Matrix", "Not a Square Matrix"));
	if (pow < 0)
	{
		if (pow == -1)
			return this->conv();
		throw(ErrorIndex("Operator ^", "Matrix", "Wrong Power"));
	}
	if (pow == 0)
		return this->E();
	Matrix<T> res(*this);
	for (int i = 0; i < pow - 1; i++)
		res = res * (*this);
	return res;
}

/*
template<class T> const Matrix<T> Matrix<T>::operator ^(const size_t& pow) const
{
	if (!this->isSquare())
		throw(ErrorSize("operator ^", "Matrix", "Not a Square Matrix"));

	Matrix<T> res(*this);
	for (size_t i = 0; i < pow - 1; i++)
		res = res * (*this);
	return res;
}
*/

#endif // !_MATRIX_OPERATORS_H
