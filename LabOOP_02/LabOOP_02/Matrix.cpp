#include "stdafx.h"

#include "Matrix.h"

using namespace std;
#include "MatrixBase.h"
/*
template<class T> Matrix<T>::Matrix()
{
	this->row = 0;
	this->col = 0;
	this->mat = nullptr;
}
*/

/*
template<class T> Matrix<T>::Matrix(size_t row, size_t col)
{
	Matrix(row, col, 0);
}
*/

/*
template<class T> Matrix<T>::Matrix(size_t row, size_t col, T value)
{
	cout << "Call Constructor";
	this->row = row;
	this->col = col;
	this->mat = new T*[this->row];
	for (size_t i = 0; i < this->row; i++)
	{
		this->mat[i] = new T[this->col];
		for (size_t j = 0; j < this->col; j++)
			this->mat[i][j] = value;
	}

}*/


/*
template<class T> void Matrix<T>::show()
{
	for (size_t i = 0; i < this->row; i++)
	{
		for (size_t j = 0; j < this->col; j++)
			cout << this->mat[i][j] << " ";
		cout << endl;
	}
}
*/


/*
template<class T> Matrix<T>::~Matrix()
{
	for (size_t i = 0; i < this->row; i++)
		delete[] this->mat[i];
	delete[] this->mat;
	this->row = 0;
	this->col = 0;
}
*/