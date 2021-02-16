#include "points.h"

#define _USE_MATH_DEFINES
#include <math.h>

void point_print(Point *p)
{
	cout << p->x << ' ' << p->y << ' ' << p->z << endl;
}

Point * point_from_xyz(double x, double y, double z)
{
	Point *p = new Point;
	p->x = x;
	p->y = y;
	p->z = z;
	return p;
}

Point * point_from_arr(double arr[3])
{
	return point_from_xyz(arr[0], arr[1], arr[2]);
}

void point_del(Point *p)
{
	delete p;
}

void point_copy(Point *p1, Point *p2)
{
	p1->x = p2->x;
	p1->y = p2->y;
	p1->z = p2->z;
}

void point_move(Point *p, double dx, double dy, double dz)
{
	p->x += dx;
	p->y += dy;
	p->z += dz;
}

void point_scale(Point *p, double kx, double ky, double kz, Point *M)
{
	p->x = kx * p->x + (1 - kx) * M->x;
	p->y = ky * p->y + (1 - ky) * M->y;
	p->z = kz * p->z + (1 - kz) * M->z;
}

/*
quay theo truc Oz
toạ đô x và y thay đổi
*/
void point_rotate_by_oz(Point *p, double angle, double x, double y)
{
	double x0 = p->x;
	double y0 = p->y;
	angle = angle * M_PI / 180;
	p->x = x + (x0 - x) * cos(angle) + (y0 - y) * sin(angle);
	p->y = y - (x0 - x) * sin(angle) + (y0 - y) * cos(angle);
}
// thế x bởi z và y bởi x
void point_rotate_by_oy(Point *p, double angle, double x, double z)
{
	double z0 = p->z;
	double x0 = p->x;
	angle = angle * M_PI / 180;
	p->z = z + (z0 - z) * cos(angle) + (x0 - x) * sin(angle);
	p->x = x - (z0 - z) * sin(angle) + (x0 - x) * cos(angle);
}

// the x bởi y và thế y bởi z
void point_rotate_by_ox(Point *p, double angle, double y, double z)
{
	double y0 = p->y;
	double z0 = p->z;
	angle = angle * M_PI / 180;
	p->y = y + (y0 - y) * cos(angle) + (z0 - z) * sin(angle);
	p->z = z - (y0 - y) * sin(angle) + (z0 - z) * cos(angle);
}
