#include "stdafx.h"

#include "vectors.h"
#include "PointModif.h"
using namespace std;

Vector * vector_from_xyz(double x, double y, double z)
{
	Vector *v = new Vector;
	v->x = x;
	v->y = y;
	v->z = z;
	return v;
}

Vector * vector_from_point(Point_3D_t*A, Point_3D_t*B)
{
	Vector *v = new Vector;
	v->x = B->x - A->x;
	v->y = B->y - A->y;
	v->z = B->z - A->z;
	return v;
}

void vector_del(Vector *v)
{
	delete v;
}

/*
|a b|
|c d| = ad - bc
*/
double delta(double a, double b, double c, double d)
{
	return a * d - b * c;
}

Vector * vector_mult(Vector *u, Vector *v)
{
	double x = delta(u->y, u->z, v->y, v->z);
	double y = -delta(u->x, u->z, v->x, v->z);
	double z = delta(u->x, u->y, v->x, v->y);
	Vector *new_vec = vector_from_xyz( x, y, z );
	return new_vec;
}

void vector_print(Vector *v)
{
	cout << v->x << " " << v->y << " " << v->z << endl;
}

bool vector_is_zero(Vector *v)
{
	if (v->x == 0 && v->y == 0 && v->z == 0)
		return true;
	else
		return false;
}
