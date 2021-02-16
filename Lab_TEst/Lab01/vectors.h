#ifndef _VECTOR_H_
#define _VECTOR_H_

#include "points.h"
#include <iostream>


struct Vector
{
	double x;
	double y;
	double z;
};
Vector * vector_from_point(Point *A, Point *B);

void vector_del(Vector *v);

Vector * vector_mult(Vector *u, Vector *v);

void vector_print(Vector *v);

bool vector_is_zero(Vector *v);

#endif // !_VECTOR_H_