#pragma once
#ifndef  _MATRIX_H_
#define _MATRIX_H_

#include "Constant.h"
#include <stdio.h>
#include <stdlib.h>

Error_t free_matrix(int **mat, int n);

int ** matrix_alloc(int n, int m);

Error_t input_matrix(int **mat, FILE *fsrc, int n, int m);

Error_t scan_matrix(int ***res, FILE *fsrc, int count);

#endif // ! _MATRIX_H_
