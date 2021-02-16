#include "stdafx.h"

#if 1
#include "MatrixBase.h"



// Constructor

MatrixBase::MatrixBase() : row(0), col(0)
{}

MatrixBase::MatrixBase(size_t row, size_t col)
{
	this->setCol(col);
	this->setRow(row);
}


// Methods

size_t MatrixBase::getRow()
{
	return this->row;
}

size_t MatrixBase::getRow() const
{
	return this->row;
}

void MatrixBase::setRow(size_t row)
{
	this->row = row;
}

size_t MatrixBase::getCol()
{
	return this->col;
}

size_t MatrixBase::getCol() const
{
	return this->col;
}

void MatrixBase::setCol(size_t col)
{
	this->col = col;
}

size_t MatrixBase::size()
{
	return this->getCol() * this->getRow();
}

// Destructor

MatrixBase::~MatrixBase() = default;

#endif

