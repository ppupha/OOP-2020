#ifndef _POINT_H_
#define _POINT_H_

#include <iostream>
using namespace std;

struct Point
{
	double x;
	double y;
	double z;
};

void point_print(Point *p);

Point * point_from_xyz(double x, double y, double z);

Point * point_from_arr(double arr[3]);

void point_del(Point *p);

void point_copy(Point *p1, Point *p2);

void point_move(Point *p, double dx, double dy, double dz);

void point_scale(Point *p, double kx, double ky, double kz, Point *M);

void point_rotate_by_oz(Point *p, double angle = 45, double x = 0, double y = 0);

void point_rotate_by_oy(Point *p, double angle = 45, double x = 0, double z = 0);

void point_rotate_by_ox(Point *p, double angle = 45, double y = 0, double z = 0);


#endif // !_POINT_H_

