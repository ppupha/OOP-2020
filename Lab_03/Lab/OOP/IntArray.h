#pragma once
#ifndef _INT_ARRAY_H_
#define _INT_ARRAY_H_

#include "Constant.h"
#include <stdio.h>

int * alloc_int_arr(int n);

void free_int_arr(int * int_arr);

Error_t read_from_file_int_arr(int *int_arr, int n, FILE *fsrc);

#endif // !_INT_ARRAY_H_
