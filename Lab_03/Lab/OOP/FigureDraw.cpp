#include "stdafx.h"
#include "FigureDraw.h"
#include "PointModif.h"
#include "DrawInit.h"


void line_draw(Easel_t *easel, Point_3D_t pb, Point_3D_t pe)
{
	Point_2D_t p1 = point3dto2d(pb, easel);
	Point_2D_t p2 = point3dto2d(pe, easel);
	easel->canvas->DrawLine(Pens::Black, p1.x, p1.y, p2.x, p2.y);
}

void edges_draw(Figure_t *figure, Easel_t *easel)
{
	for (int i = 0; i < figure->pointNum; ++i)
		for (int j = i + 1; j < figure->pointNum; ++j)
			if (figure->matrix_contiguities[i][j])
				line_draw(easel, figure->pointArr[i], figure->pointArr[j]);
}

void prepare_canvas(Easel_t *easel)
{
	easel->canvas->Clear(easel->backcolor);
}


Error_t figure_draw(Figure_t *figure, wrapper_canvas* canva)
{
	Error_t rc = ERROR_DRAW;
	Easel_t easel = init_easel(canva);
	if (figure->pointNum > 0)
	{
		prepare_canvas(&easel);
		edges_draw(figure, &easel);
		rc = OK;
	}
	return rc;
}