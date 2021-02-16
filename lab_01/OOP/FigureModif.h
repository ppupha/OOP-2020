#ifndef _FigureModif_H_
#define _FigureModif_H_

#include "FigureInit.h"
#include "Constant.h"
#include "DrawInit.h"
#include "ModifInit.h"

Error_t figure_rotate_ox(Figure_t *f, const Rotate_data_t *rodata);

Error_t figure_rotate_oy(Figure_t *f, const Rotate_data_t *rodata);

Error_t figure_rotate_oz(Figure_t *f, const Rotate_data_t *rodata);

Error_t figure_rotate(Figure_t *f, const Rotate_data_t *rodata);

Error_t figure_scale(Figure_t *f, const Scale_data_t *scdata);

Error_t figure_shift(Figure_t *f, const Shift_data_t *shdata);

Error_t figure_mode(Figure_t *f, const Modif_t *modif);

//Point_2D_t *FigureModifs(Figure_t *figure, Easel_t *easel);

#endif //_FigureModif_H_