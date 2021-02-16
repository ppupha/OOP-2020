
#ifndef _ITER_H_
#define _ITER_H_

/*
********************************************************

Class Bsse Iterator

********************************************************
*/

template<class T> class  BaseIter
{
	//friend class Matrix<T>;
protected:
	weak_ptr<shared_ptr<T[]>[]> mat;
	size_t rowindex;
	size_t colindex;
	size_t row;
	size_t col;

	size_t pos() { return rowindex * col + colindex; }
	size_t pos() const { return rowindex * col + colindex; }

public:
	// Constructor
	BaseIter(weak_ptr<shared_ptr<T[]>[]> ma, size_t r, size_t c, size_t rindex , size_t cindex );
	BaseIter(const BaseIter& it) = default;
	//Operator


	BaseIter<T>& operator++ ();// ++obj
	BaseIter<T> operator++(int);// obj++
	BaseIter<T>& operator-- ();
	BaseIter<T> operator--(int);// obj++
	BaseIter<T> operator +(int);
	BaseIter<T> operator -(int);

	bool operator == (const BaseIter<T>&);
	bool operator != (const BaseIter<T>&);
	bool operator < (const BaseIter<T>&);
	bool operator > (const BaseIter<T>&);
	bool operator <= (const BaseIter<T>&);
	bool operator >= (const BaseIter<T>&);
	// Destructor
	//...
};


// Constructor
template<class T> BaseIter<T>::BaseIter(weak_ptr<shared_ptr<T[]>[]> ma, size_t r, size_t c, size_t rindex , size_t cindex)
	: mat(ma), row(r), col(c), rowindex(rindex), colindex(cindex)
{

}


// Operator

template<class T> BaseIter<T>& BaseIter<T>::operator ++()
{
	if (rowindex == row - 1 && colindex == col)
		return *this;

	colindex++;

	if (colindex == col)
	{
		colindex = 0;
		rowindex++;
	}

	return *this;
}

template<class T> BaseIter<T> BaseIter<T>::operator ++(int t)
{
	BaseIter<T> it(*this);
	++(*this);
	return it;
}

template<class T> BaseIter<T>& BaseIter<T>::operator --()
{
	if (rowindex == 0 && colindex == 0)
		throw(ErrorIndex("operator --", "Base Operator", "Index Out of Range"));
	if (colindex == 0)
	{
		colindex = col - 1;
		rowindex--;
	}
	else
	{
		colindex--;
	}

	return *this;
}

template<class T> BaseIter<T> BaseIter<T>::operator --(int t)
{
	BaseIter<T> it(*this);
	--(*this);
	return it;
}


template<class T> BaseIter<T> BaseIter<T>::operator +(int t)
{
	for (int i = 0; i < t; i++)
		(this)++;
	return *this;
}

template<class T> BaseIter<T> BaseIter<T>::operator -(int t)
{
	for (int i = 0; i < t; i++)
		(this)--;
	return *this;
}



template<class T> bool BaseIter<T>::operator ==(const BaseIter<T>& iter)
{
	return this->pos() == iter.pos();
}

template<class T> bool BaseIter<T>::operator != (const BaseIter<T>& iter)
{
	return !((*this) == iter);
}

template<class T> bool BaseIter<T>::operator < (const BaseIter<T>& iter)
{
	return this->pos() < iter.pos();
}

template<class T> bool BaseIter<T>::operator > (const BaseIter<T>& iter)
{
	return this->pos() > iter.pos();
}

template<class T> bool BaseIter<T>::operator <= (const BaseIter<T>& iter)
{
	return !(*this > iter);
}

template<class T> bool BaseIter<T>::operator >= (const BaseIter<T>& iter)
{
	return !(*this < iter);
}


/*
********************************************************

Class Iterator

********************************************************
*/

template<class T> class  Iter : public BaseIter<T>
{
private:

public:
	Iter(shared_ptr<shared_ptr<T[]>[]>& ma, size_t r, size_t c, size_t rindex, size_t cindex);
	Iter(const Iter& it) = default;

	const T& operator* () const;
	T& operator* ();
	//->

};

template<class T> Iter<T>::Iter(shared_ptr<shared_ptr<T[]>[]>& ma, size_t r, size_t c, size_t rindex, size_t cindex)
	: BaseIter(ma, r, c, rindex, cindex)
{
}

template<class T> T& Iter<T>::operator * ()
{
	shared_ptr<shared_ptr<T[]>[]> m(this->mat);
	shared_ptr<T[]> arr(m[rowindex]);
	return arr[colindex];
}


/*
********************************************************

Class Const Iterator

********************************************************
*/

template<class T> class  Const_Iter : public BaseIter<T>
{
public:
	Const_Iter(const shared_ptr<shared_ptr<T[]>[]>& ma, size_t r, size_t c, size_t rindex = 0, size_t cindex = 0);
	Const_Iter(const Const_Iter& it) = default;

	const T& operator* () const;
	// ->

};

template<class T> Const_Iter<T>::Const_Iter(const shared_ptr<shared_ptr<T[]>[]>& ma, size_t r, size_t c, size_t rindex, size_t cindex)
	: BaseIter(ma, r, c, rindex, cindex)
{
}

template<class T> const T& Const_Iter<T>::operator * ()
{
	shared_ptr<shared_ptr<T[]>[]> m(this->mat);
	shared_ptr<T[]> arr(m[rowindex]);
	return arr[colindex];
}



#endif // !_ITER_H_
