#ifndef _Init_H_
#define _Init_H_

#include <gcroot.h>
#include "PointInit.h"
#include "FigureInit.h"

using namespace System::Drawing;

struct Easel_t
{
	gcroot<Graphics^> canvas;
	gcroot<Color> backcolor;
	Point_2D_t centre;
};
struct wrapper_canvas
{
	gcroot<System::Windows::Forms::PictureBox^> pb;
};

Easel_t init_easel(const wrapper_canvas *canva);

#endif //_Init_H_