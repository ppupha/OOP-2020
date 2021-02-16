#pragma once
#ifndef _MATRIX_CONDES_H_
#define _MATRIX_CONDES_H_

// Constructor

template<class T> Matrix<T>::Matrix(size_t row, size_t col)
{
	this->alloc(row, col);
}

template<class T> Matrix<T>::Matrix(size_t row, size_t col, const T& value)
{
	this->alloc(row, col);

	for (size_t i = 0; i < this->getRow(); i++)
		for (size_t j = 0; j < this->getCol(); j++)
			this->mat[i][j] = value;
}

template<class T> Matrix<T>::Matrix(const Matrix<T>& matrix)
{
	this->copy(matrix);
}

template<class T> Matrix<T>::Matrix(Matrix<T>&& matrix)
{
	this->move(matrix);
}


template <class T>
Matrix<T>::Matrix(std::initializer_list<std::initializer_list<T>> lst)
{
	(*this) = Matrix(lst.size(), lst.size() ? lst.begin()->size() : 0);
	size_t i = 0, j = 0;
	for (const auto& l : lst)
	{
		for (T v : l)
		{
			(*this)[i][j] = v;
			j++;
		}
		j = 0;
		i++;
	}
}

// Destructor
template<class T> Matrix<T>::~Matrix()
{
	//this->free();
}

#endif // !_MATRIX_CONDES_H_
