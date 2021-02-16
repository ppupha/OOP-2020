#include "stdafx.h"
#include "Matrix.h"
#include "IntArray.h"

Error_t free_matrix(int **mat, int n)
{
	Error_t rc = OK;
	for (int i = 0; i < n; i++)
		free_int_arr(mat[i]);

	delete[] mat;
	return rc;
}

int ** matrix_alloc(int n, int m)
{
	int **tmp_matrix = new int*[n];	  // cấp bộ nhớ cho mảng con trỏ
	if (!tmp_matrix)
		return tmp_matrix;

	for (int i = 0; i < n; ++i)
	{
		// cấp cho từng hàng
		tmp_matrix[i] = alloc_int_arr(m);	 // calloc bộ nhớ cho hàng thứ i 
		if (!tmp_matrix[i])			 // nếu không được
			free_matrix(tmp_matrix, i);	// giải phóng bộ nhớ
	}

	return tmp_matrix;
}

Error_t input_matrix(int **mat, FILE *fsrc, int n, int m)
{
	Error_t rc = OK;
	for (int i = 0; i < n && rc == OK; ++i)
		rc = read_from_file_int_arr(mat[i], m, fsrc);
	return rc;
}

Error_t scan_matrix(int ***res, FILE *fsrc, int count)
{
	Error_t rc = OK;

	int **tmp_matrix = matrix_alloc(count, count);
	if (!tmp_matrix)
		return ERROR_MEMORY;

	rc = input_matrix(tmp_matrix, fsrc, count, count);

	if (rc == OK)
		*res = tmp_matrix;
	else
		free_matrix(tmp_matrix, count);

	return rc;
}