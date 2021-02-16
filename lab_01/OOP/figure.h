#ifndef _FIGURE_H_
#define _FIGURE_H_

#include <iostream>
#include <fstream>
using namespace std;

#include "points.h"
#include "vectors.h"

struct Figure
{
	Point_3D_t*pointArr;
	int pointNum;
};

void figure_print(Figure *f);

Figure * figure_init(int n);

void figure_del(Figure *f);

Figure * figure_file_input(string filename);

bool check_coplanar(Point_3D_t*A, Point_3D_t*B, Point_3D_t*C, Point_3D_t*D);

bool figure_check(Figure *f);

void figure_move(Figure *f, double dx, double dy, double dz);

void figure_scale(Figure *f, double kx, double ky, double kz, Point_3D_t*M);

void figure_rotate_by_ox(Figure *f, double angle, double x, double y);

void figure_rotate_by_oy(Figure *f, double angle = 45.0, double x = 0.0, double z = 0.0);

void figure_rotate_by_oz(Figure *f, double angle = 45.0, double x = 0.0, double y = 0.0);

#endif // !_FIGURE_H_

