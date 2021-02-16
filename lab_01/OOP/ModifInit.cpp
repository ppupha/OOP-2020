#include "stdafx.h"
#include "ModifInit.h"

Shift_data_t init_data_shift(void)
{
	Shift_data_t data_shift;
	data_shift.dx = 0;
	data_shift.dy = 0;
	data_shift.dz = 0;
	return data_shift;
}

Rotate_data_t init_data_rotate(void)
{
	Rotate_data_t data_rotate;
	data_rotate.angle_x = 0;
	data_rotate.angle_y = 0;
	data_rotate.angle_z = 0;
	return data_rotate;
}

Scale_data_t init_data_scale(void)
{
	Scale_data_t data_scale;
	data_scale.scale = 1.0;
	return data_scale;
}

Modif_t init_modif(void)
{
	Modif_t modif;
	modif.data_shift = init_data_shift();
	modif.data_scale = init_data_scale();
	modif.data_rotate = init_data_rotate();
	return modif;
}