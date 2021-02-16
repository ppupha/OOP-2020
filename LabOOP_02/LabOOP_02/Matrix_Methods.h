#ifndef _MATRIX_METHODS_H_
#define  _MATRIX_METHODS_H_

//#include "Matrix.h"
#include <stdlib.h>
using namespace std;

template<class T> void Matrix<T>::alloc(const size_t row, const size_t col)
{
	if (row == 0 || col == 0)
		throw(ErrorEmpty("Alloc", "Matrix", "Alloc Empty Matrix"));
	
	this->setRow(row);
	this->setCol(col);

	try
	{

		this->mat = shared_ptr< shared_ptr< T[] >[] >(new shared_ptr<T[]>[this->getRow()]);
		for (size_t i = 0; i < this->getRow(); i++)
		{
			this->mat[i] = shared_ptr<T[]>( new T[this->getCol()]);
			for (size_t j = 0; j < this->getCol(); j++)
				this->mat[i][j] = 0.0;
		}
	}
	catch (exception& err)
	{
		cout << err.what();
	}
}

/*
template<class T> void Matrix<T>::free()
{
	//delete[] this->mat;
	//for (size_t i = 0; i < this.getRow(); i++)
	//	(*this)[i].free();
	//delete[] this->mat;
}
*/

template<class T> void Matrix<T>::copy(const Matrix<T>& matrix)
{
	this->alloc(matrix.getRow(), matrix.getCol());

	if (!this->isSizeEqual(matrix))
		throw(ErrorSize("Copydata", "Matrix", "Cant copy data from matrix with anothor size"));

	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->getCol(); j++)
			(*this)[i][j] = matrix[i][j];
}

template<class T> Iter<T> Matrix<T>::begin()
{
	if (this->isEmpty())
		throw(ErrorEmpty("begin", "Matrix", "Cant get Begin in Empty Matrix!!!"));
	return Iter<T>(this->mat, this->getRow(), this->getCol(), 0, 0);
}

template<class T> Iter<T> Matrix<T>::end()
{
	if (this->isEmpty())
		throw(ErrorEmpty("end", "Matrix", "Cant get End in Empty Matrix!!!"));
	return Iter<T>(this->mat, this->getRow(), this->getCol(), this->getRow() - 1, this->getCol() - 1);
}

template<class T> Const_Iter<T> Matrix<T>::cbegin() const
{
	if (this->isEmpty())
		throw(ErrorEmpty("begin", "Matrix", "Cant get Begin in Empty Matrix!!!"));
	Const_Iter<T> cit(this->mat, this->getRow(), this->getCol(), 0, 0);
	return cit;
}

template<class T> Const_Iter<T> Matrix<T>::cend() const
{
	if (this->isEmpty())
		throw(ErrorEmpty("end", "Matrix", "Cant get End in Empty Matrix!!!"));
	return Const_Iter<T>(this->mat, this->getRow(), this->getCol(), this->getRow() - 1, this->getCol() - 1);
}
/*
template<class T> Const_Iter<T> Matrix<T>::cbegin()
{
	if (this->isEmpty())
		throw(ErrorEmpty("begin", "Matrix", "Cant get Begin in Empty Matrix!!!"));
	return Const_Iter<T>(this->mat, this->getRow(), this->getCol(), 0, 0);
}

template<class T> Const_Iter<T> Matrix<T>::cend() 
{
	if (this->isEmpty())
		throw(ErrorEmpty("end", "Matrix", "Cant get End in Empty Matrix!!!"));
	return Const_Iter<T>(this->mat, this->getRow(), this->getCol(), this->getRow() - 1, this->getCol() - 1);
}
*/

template<class T> bool Matrix<T>::isSizeEqual(const Matrix<T>& matrix) const
{
	return (this->getRow() == matrix.getRow() && this->getCol() == matrix.getCol());
}

template<class T> bool Matrix<T>::isEmpty() const
{
	return (this->getRow() <= 0 || this->getCol() <= 0 || !this->mat);
}

template<class T> bool Matrix<T>::isSquare() const
{
	return this->getRow() == this->getCol();
}

template<class T> void output(Matrix<T>& matrix)
{
	Iter<int> start = matrix.begin();
	Iter<int> end = matrix.end();
	for (Iter<int> it = start; it < end; it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

template<class T> void Matrix<T>::move(Matrix<T>& matrix)
{
	this->setRow(matrix.getRow());
	this->setCol(matrix.getCol());
	this->mat = matrix.mat;
	matrix.mat = nullptr;
}

template<class T> T Matrix<T>::det() const
{
	if (!this->isSquare())
		throw(ErrorSize("det", "Matrix", "Not Square MAtrix"));

	T zero{};
	size_t n = this->getRow();

	Matrix<T> L(n, n, zero);
	Matrix<T> U(n, n, zero);
	Matrix<T> A(*this);

	for (size_t k = 0; k < n; k++)
	{
		U[k][k] = A[k][k];
		L[k][k] = 1;
		for (size_t i = k + 1; i < n; i++)
		{
			L[i][k] = A[i][k] / U[k][k];
			U[k][i] = A[k][i];
			U[i][k] = 0;
			L[k][i] = 0;
		}
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				A[i][j] = A[i][j] - L[i][k] * U[k][j];
	}

	T tmp1{};
	tmp1++;
	T tmp2{};
	tmp2++;
	for (size_t i = 0; i < n; i++)
	{
		tmp1 *= U[i][i];
		tmp2 *= L[i][i];
	}
	return tmp1 * tmp2;
}

template<class T> Matrix<T> Matrix<T>::E() const
{
	if (!this->isSquare())
		throw(ErrorSize("E", "Matirx", "Not a Square Matrix"));

	T zero{};
	T one = ++zero;
	zero--;
	Matrix<T> res(this->getRow(), this->getCol(), zero);
	for (size_t i = 0; i < this->getRow(); i++)
		res[i][i] = one;
	return res;
}

/*
template<class T> void Matrix<T>::input()
{
	this->free();
	int row, col;
	cout << "Input Row: ";
	cin >>row;

	if (row <= 0)
		throw(ErrorSize("Input", "Matrix", "Input row is wrong"));

	cout << "Input Col: ";
	cin >> col;
	if (col <= 0)
		throw(ErrorSize("Input", "Matrix", "Input column is wrong"));
	this->alloc(row, col);
	cout << "Input Matrix: " << endl;
	cin >> (*this);
}
*/

#endif // !_MATRIX_METHODS_H_
