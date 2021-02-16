#if 1

#ifndef _MATRIX_BASE_H_
#define _MATRIX_BASE_H_

class MatrixBase
{
protected:
	size_t row;
	size_t col;
public:
	// Constructor
	MatrixBase();
	MatrixBase(size_t, size_t);


	// Row Getter and Setter 
	size_t getRow();
	size_t getRow() const;
	void setRow(size_t row);


	// Column Getter and Setter
	size_t getCol();
	size_t getCol() const;
	void setCol(size_t col);

	size_t size();

	//Destructor
	//...virtual = defaul
	virtual ~MatrixBase() = 0;
};
#endif

#endif
