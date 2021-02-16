#include "stdafx.h"
#include "FigureModif.h"
#include "PointModif.h"
#include "Constant.h"

#define _USE_MATH_DEFINES
#include <math.h>

double angletorad(int angle)
{
	return (angle * M_PI / 180);
}

Error_t figure_rotate_ox(Figure_t *f, const Rotate_data_t *rdata)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	double angle = angletorad(rdata->angle_x);
	for (int i = 0; i < f->pointNum; ++i)
		point_rotate_by_ox(f->pointArr + i, angle);

	return rc;
}

Error_t figure_rotate_oy(Figure_t *f, const Rotate_data_t *rdata)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	double angle = angletorad(rdata->angle_y);
	for (int i = 0; i < f->pointNum; ++i)
		point_rotate_by_oy(f->pointArr + i, angle);
	return rc;
}

Error_t figure_rotate_oz(Figure_t *f, const Rotate_data_t *rdata)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	double angle = angletorad(rdata->angle_z);
	for (int i = 0; i < f->pointNum; ++i)
		point_rotate_by_oz(f->pointArr + i, angle);
	return rc;
}

Error_t figure_rotate(Figure_t *f, const Rotate_data_t *rdata)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	figure_rotate_ox(f, rdata);  // figure_rotate_ox
	figure_rotate_oy(f, rdata);
	figure_rotate_oz(f, rdata);
	return rc;
}

Error_t figure_scale(Figure_t *f, const Scale_data_t *sdata)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	double k = sdata->scale;
	for (int i = 0; i < f->pointNum; ++i)
	{
        point_scale(f->pointArr + i, k, k, k);
	}
	return rc;
}

Error_t figure_shift(Figure_t *f, const Shift_data_t *sdata)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	double dx = sdata->dx;
	double dy = sdata->dy;
	double dz = sdata->dz;

	for (int i = 0; i < f->pointNum; ++i)
		point_move(f->pointArr + i, dx, dy, dz);
	return rc;
}

Error_t figure_mode(Figure_t *f, const Modif_t *modif)
{
	Error_t rc = OK;
	if (f->pointNum == 0)
		return ERROR_NO_FIGURE;

	figure_shift(f, &(modif->data_shift));
	figure_scale(f, &(modif->data_scale));
	figure_rotate(f, &(modif->data_rotate));
	return rc;
}
