#pragma once
#ifndef _FIGURE_INIT_
#define _FIGURE_INIT_
#include "PointInit.h"

struct Figure_t
{
	int pointNum;
	Point_3D_t *pointArr;
	int **matrix_contiguities;
};

Figure_t init_figure(void);

#endif // !_FIGURE_INIT_
