#pragma once
#ifndef _ARRAY_CONDES_H_
#define _ARRAY_CONDES_H_

// Constructor
template<class T> Array<T>::Array()
{
	this->len = 0;
	this->arr = nullptr;
}

template<class T> Array<T>::Array(shared_ptr<T[]> arr, size_t size)
{
	this->len = size;
	this->arr = arr;
}

template<class T> Array<T>::~Array()
{}

#endif // !_ARRAY_CONDES_H_
