#pragma once
#ifndef _ARRAY_OPERATORS_H_
#define _ARRAY_OPERATORS_H_


template<class T> T Array<T>::operator*(const Array<T>& row) const
{
	if (this->len != row.len)
		throw(ErrorMult("Operator '*'", "Array", "Cant not mult 2 array with diff size"));
	T res();
	for (size_t i = 0; i < this->len; i++)
		res += (*this)[i] * row[i];
	return res;
}

template<class T> T& Array<T>::operator[](const size_t index)
{
	if (index >= this->len)
		throw(ErrorIndex("operator '[]'", "Array", "Index out of Range"));
	return this->arr[index];
}

template<class T> const T& Array<T>::operator[](const size_t index) const
{
	if (index >= this->len)
		throw(ErrorIndex("operator '[]'", "Array", "Index out of Range"));
	return this->arr[index];
}

template<class T> istream& operator >> (istream& is, Array<T>& row)
{
	for (size_t i = 0; i < row.getlen(); i++)
		cin >> row[i];
	return is;

}

template<class T> ostream& operator << (ostream& os, Array<T>& row)
{
	if (row.isEmpty())
		throw(ErrorEmpty("operator '>>'", "Array", "Output Empty Array"));
	for (size_t i = 0; i < row.getlen(); i++)
		cout << row[i] << "  ";
	cout << endl;
	return os;

}
#endif // !_ARRAY_OPERATORS_H_
