#include "stdafx.h"
#include "PointArr.h"

Error_t read_from_file_point(Point_3D_t *point, FILE *fsrc)
{
	Error_t rc = OK;
	if (fscanf(fsrc, "%lf %lf %lf", &(point->x), &(point->y), &(point->z)) != 3)
	{
		rc = ERROR_FILE;
	}
	return rc;
}

Error_t read_from_file_point_arr(Point_3D_t *pointArr, FILE *fsrc, int count)
{
	Error_t rc = OK;
	for (int i = 0; i < count && rc == OK; ++i)
		rc = read_from_file_point(&(pointArr[i]), fsrc);

	return rc;
}

Point_3D_t * alloc_point_arr(int count)
{
	Point_3D_t *pointArr = new Point_3D_t[count];
	return pointArr;
}

void free_point_arr(Point_3D_t *pointArr, int count)
{
	delete[] pointArr;
}
/*
Scan Point Array from file
*/
Error_t scan_point_arr(Point_3D_t **res, FILE *fsrc, int count)
{
	Error_t rc = OK;
	Point_3D_t *tmp_pointArr = alloc_point_arr(count);
	
	if (!tmp_pointArr)
		return ERROR_MEMORY;

	rc = read_from_file_point_arr(tmp_pointArr, fsrc, count);

	if (rc == OK)
		*res = tmp_pointArr;
	else
		free_point_arr(tmp_pointArr, count);
	return rc;
}