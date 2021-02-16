#include "stdafx.h"
#include "PointModif.h"
#include <math.h>

void point_del(Point_3D_t*p)
{
	delete p;
}

void point_copy(Point_3D_t*p1, Point_3D_t*p2)
{
	p1->x = p2->x;
	p1->y = p2->y;
	p1->z = p2->z;
}

void point_move(Point_3D_t *p, double dx, double dy, double dz)
{
	p->x += dx;
	p->y += dy;
	p->z += dz;
}

void point_scale(Point_3D_t *p, double kx, double ky, double kz)
{
	Point_3D_t *M = new Point_3D_t;
	M->x = 0;
	M->y = 0;
	M->z = 0;
	p->x = kx * p->x + (1 - kx) * M->x;
	p->y = ky * p->y + (1 - ky) * M->y;
	p->z = kz * p->z + (1 - kz) * M->z;
}

/*
quay theo truc Oz
toạ đô x và y thay đổi
*/
void point_rotate_by_oz(Point_3D_t*p, double angle, double x, double y)
{
	double x0 = p->x;
	double y0 = p->y;
	p->x = x + (x0 - x) * cos(angle) + (y0 - y) * sin(angle);
	p->y = y - (x0 - x) * sin(angle) + (y0 - y) * cos(angle);
}
// thế x bởi z và y bởi x
void point_rotate_by_oy(Point_3D_t*p, double angle, double x, double z)
{
	double z0 = p->z;
	double x0 = p->x;
	p->z = z + (z0 - z) * cos(angle) + (x0 - x) * sin(angle);
	p->x = x - (z0 - z) * sin(angle) + (x0 - x) * cos(angle);
}

// the x bởi y và thế y bởi z
void point_rotate_by_ox(Point_3D_t*p, double angle, double y, double z)
{
	// x = const
	double y0 = p->y;
	double z0 = p->z;
	p->y = y + (y0 - y) * cos(angle) + (z0 - z) * sin(angle);
	p->z = z - (y0 - y) * sin(angle) + (z0 - z) * cos(angle);
}

Point_2D_t point3dto2d(Point_3D_t p, Easel_t *easel)
{
	Point_2D_t res;
	res.x = p.x + easel->centre.x;
	res.y = p.y + easel->centre.y;
	return res;
}
