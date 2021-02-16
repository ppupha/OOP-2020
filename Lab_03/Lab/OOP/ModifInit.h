#pragma once
#ifndef _MODIF_INIT_H_
#define _MODIF_INIT_H

#include "DrawInit.h"

struct Shift_data_t
{
	int dx;
	int dy;
	int dz;
};

struct Rotate_data_t
{
	int angle_x;
	int angle_y;
	int angle_z;
};

struct Scale_data_t
{
	double scale;
};

struct Modif_t
{
	Shift_data_t data_shift;
	Scale_data_t data_scale;
	Rotate_data_t data_rotate;
};

union Form_data_t
{
	Shift_data_t data_shift;
	Scale_data_t data_scale;
	Rotate_data_t data_rotate;
	wrapper_canvas* canva;
	char *filename;
};

Modif_t init_modif(void);

Form_data_t init_form_data(void);



#endif // !_MODIF_INIT_H_
