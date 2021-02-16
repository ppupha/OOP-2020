#if 1

#pragma once
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include "MatrixBase.h"
#include <exception>
#include <iostream>
#include <memory>
using namespace std;

#include "Array.h"

/*
********************************************************

Class Matrix

********************************************************
*/
template<class T> class Matrix : public MatrixBase 
{
private:
	shared_ptr<shared_ptr<T[]>[]> mat;// smart poiter OK
	void alloc(const size_t, const size_t);
	Matrix<T> conv() const; // Converse Matrix A^-1

public:

	// Constructor
	Matrix(size_t row, size_t col);
	Matrix(size_t row, size_t col, const T& value);
	explicit Matrix(const Matrix<T>& matrix); // copy constructor
	Matrix(Matrix<T>&& matrix) noexcept; // move constructor
	Matrix(initializer_list<initializer_list<T>> lst); //A = {{}, {}} OK

	Matrix<T>& operator = (const Matrix<T> &matrix);
	Matrix<T>& operator = (Matrix<T> && matrix); // move OK
	// = list

	//Methods
	void move(Matrix<T>& matrix);
	void copy(const Matrix<T>&);

	Iter<T> begin();
	Iter<T> end();

	Const_Iter<T> begin() const;
	Const_Iter<T> end() const;

	Const_Iter<T> cbegin() const; // const OK
	Const_Iter<T> cend() const;

	bool isSizeEqual(const Matrix<T>&) const; 
	bool isEmpty() const;
	bool isSquare() const;
	Matrix<T> E() const; 
	T det() const;

	//operator
	bool operator == (const Matrix<T> &matrix) const;
	bool operator != (const Matrix<T> &matrix) const;

	Matrix<T> operator + (const Matrix<T> &matrix) const;
	void operator += (const Matrix<T> &matrix); // += OK

	Matrix<T> operator - (const Matrix<T> &matrix) const;
	void operator -= (const Matrix<T> &matrix); // -= OK

	Matrix<T> operator ^ (const int pow) const; //A^2 = A * A

	Matrix<T> operator * (const T &value) const;
	void operator *= (const T	&value); // *= OK
//	Matrix<T> operator * (const T& value, const Matrix<T> &matrix);
	Matrix<T> operator * (const Matrix<T> &matrix) const;
	void operator *= (const Matrix<T> &matrix); // *= OK

//	ostream& operator << (ostream& os, const Matrix<T>& matrix)
//	istream& operator << (istream& os, Matrix<T>& matrix)

	const Array<T> operator [] (const size_t rowindex) const;
	Array<T> operator [] (const size_t rowindex);

	Matrix<T> operator ~ () const; // Transpose Matrix A ^ T operator ~ OK
//	Matrix<T> conv() const; // Converse Matrix OK

	// Destructor
	virtual ~Matrix();
};

// Constructor - Destructor
#include "Matrix_ConDes.h"

//Methods
#include "Matrix_Methods.h"

// Operator
#include "Matrix_Operators.h"

#endif
#endif


