#pragma once
#ifndef _POINT_ARR_H_
#define _POINT_ARR_H_

#include "Constant.h"
#include <stdio.h>
#include <stdlib.h>
#include "PointInit.h"

Error_t read_from_file_point(Point_3D_t *point, FILE *fsrc);

Error_t read_from_file_points(Point_3D_t *pointArr, FILE *fsrc, int count);

void free_point_arr(Point_3D_t *pointArr, int count);

Error_t scan_point_arr(Point_3D_t **res, FILE *fsrc, int count);

#endif // !_POINT_ARR_H_
