#include "stdafx.h"
#include "FigureInit.h"

// khoi tao figure
Figure_t init_figure(void)
{
	Figure_t figure;
	figure.pointNum = 0;
	figure.pointArr = nullptr;
	figure.matrix_contiguities = nullptr;
	return figure;
}