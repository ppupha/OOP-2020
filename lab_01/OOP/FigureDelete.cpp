#include "stdafx.h"
#include "FigureDelete.h"
#include "Matrix.h"
#include "PointArr.h"

Error_t figure_delete(Figure_t *figure)
{
	free_point_arr(figure->pointArr, figure->pointNum);
	free_matrix(figure->matrix_contiguities, figure->pointNum);

	return OK;
}