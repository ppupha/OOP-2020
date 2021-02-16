#ifndef _POINT_MODIF_H_
#define _POINT_MODIF_H_

#include <iostream>
#include "PointInit.h"
#include "DrawInit.h"
using namespace std;

#include "PointInit.h"

void point_del(Point_3D_t*p);

void point_copy(Point_3D_t*p1, Point_3D_t*p2);

void point_move(Point_3D_t*p, double dx, double dy, double dz);

void point_scale(Point_3D_t*p, double kx, double ky, double kz);

void point_rotate_by_oz(Point_3D_t*p, double angle = 45, double x = 0, double y = 0);

void point_rotate_by_oy(Point_3D_t*p, double angle = 45, double x = 0, double z = 0);

void point_rotate_by_ox(Point_3D_t*p, double angle = 45, double y = 0, double z = 0);

Point_2D_t point3dto2d(Point_3D_t p, Easel_t *easel);

#endif // !_POINT_MODIF_H_

