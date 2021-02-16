#include "stdafx.h"
#include "IntArray.h"
#include <stdlib.h>

int * alloc_int_arr(int n)
{
	int * int_arr = new int[n];
	return int_arr;
}

void free_int_arr(int * int_arr)
{
	delete[] int_arr;
}

Error_t read_from_file_int_arr(int *int_arr, int n, FILE *fsrc)
{
	Error_t rc = OK;

	for (int i = 0; i < n && rc == OK; ++i)
		if (fscanf(fsrc, "%d", &(int_arr[i])) != 1)
			rc = ERROR_FILE;
	return rc;
}