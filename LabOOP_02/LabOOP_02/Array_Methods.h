#pragma once
#ifndef _ARRAY_METHODS_H_
#define _ARRAY_METHODS_H_


template<class T> void Array<T>::alloc(const size_t size)
{
	this->len = size;
	try
	{
		this->arr = new T[this->len];
	}
	catch (exception& err)
	{
		cout << err.what() << endl;
	}
}

template<class T> void Array<T>::show()
{
	if (this->isEmpty())
		throw(ErrorEmpty("show", "Array", "Cant show Empty Array"));

	for (size_t i = 0; i < this->len; i++)
		cout << (*this)[i] << "  ";
	cout << endl;
}

template<class T> void Array<T>::setlen(size_t len)
{
	this->len = len;
}

template<class T> size_t Array<T>::getlen()
{
	return this->len;
}

template<class T> Iter<T>  Array<T>::begin()
{
	if (this->isEmpty())
		throw(ErrorEmpty("begin", "Array", "Empty Array"));

	return (shared_ptr<T[]>)&(*this)[0];
}

template<class T> const Iter<T>  Array<T>::begin() const
{
	if (this->isEmpty())
		throw(ErrorEmpty("begin", "Array", "Empty Array"));

	return (shared_ptr<T[]>) & (*this)[0];
}

template<class T> Iter<T> Array<T>::end()
{
	if (this->isEmpty())
		throw(ErrorEmpty("end", "Array", "Empty Array"));
	return (shared_ptr<T[]>)&(*this)[this->len - 1] + 1;
}

template<class T> const Iter<T> Array<T>::end() const 
{
	if (this->isEmpty())
		throw(ErrorEmpty("end", "Array", "Empty Array"));
	return (shared_ptr<T[]>) & (*this)[this->len - 1] + 1;
}

template<class T> bool Array<T>::isEmpty()
{
	return this->len == 0;
}
#endif // !_ARRAY_METHODS_H_
