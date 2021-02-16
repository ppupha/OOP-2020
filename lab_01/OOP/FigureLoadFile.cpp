#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include "FigureLoadFile.h"
#include "FigureDelete.h"
#include "Matrix.h"
#include "PointArr.h"

/*
Scan from File number of points
*/
Error_t scan_count(int *res, FILE *fsrc)
{
	if (fscanf(fsrc, "%d", res) != 1 || *res <= 0)
		return ERROR_FILE;
	else
		return OK;
}

void assignment(Figure_t *figure, int count, Point_3D_t *pointArr, int **matrix)
{
	figure->pointNum = count;
	figure->pointArr = pointArr;
	figure->matrix_contiguities = matrix;
}

Error_t read_data(Figure_t *figure, FILE *fsrc)
{
	Error_t rc = OK;
	int count = 0; // number of points
	rc = scan_count(&count, fsrc);
	if (rc != OK)
		return rc;

	Point_3D_t *pointArr = nullptr;
	rc = scan_point_arr(&pointArr, fsrc, count);
	if (rc != OK)
		return rc;

	int **matrix = nullptr;
	rc = scan_matrix(&matrix, fsrc, count);
	if (rc != OK)
	{
		free_point_arr(figure->pointArr, figure->pointNum);
		//return rc;
	}

	if (rc == OK)
		assignment(figure, count, pointArr, matrix);

	return rc;
}

Error_t load_figure(Figure_t *figure, const char *filename)
{
	FILE *fsrc = fopen(filename, "r");

	if (!fsrc)
		return ERROR_FILE;
	Error_t rc = read_data(figure, fsrc);

	fclose(fsrc);
	return rc;
}

Error_t figure_load(Figure_t *figure, const char *filename)
{
	Figure_t tmp = init_figure();
    Error_t rc = load_figure(&tmp, filename);
	if (rc == OK)
	{
		figure_delete(figure);
		*figure = tmp;
	}
	return rc;
}