#pragma once
#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <exception>
#include <memory>
#include "Iter.h"
#include "Exception.h"


/*
**************************************

Class Array

**************************************
*/

template<class T> class Array
{
private:
	size_t len;
	shared_ptr<T[]> arr;
public:
	// Constructors
	Array();
	Array(shared_ptr<T[]>, size_t);

	// methods
	void alloc(const size_t index);
	void show();
	void setlen(size_t len);
	size_t getlen();
	bool isEmpty();
	Iter<T> begin();
	const Iter<T> begin() const;

	Iter<T> end();
	const Iter<T> end() const;

	// Operators
	T& operator [] (const size_t);
	const T& operator [] (const size_t) const;
	T operator * (const Array<T>&) const;

	// Destructors
	~Array();
};

// Constructor - Destructor
#include "Arrray_ConDes.h"

// Methods
#include "Array_Methods.h"

// Operators
#include "Arrray_Operators.h"

#endif