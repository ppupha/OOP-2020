#ifndef _MOD_H_
#define _MOD_H_

#include "Init.h"
#include "Constant.h"

CodeError_e Shift_Model_f(Modif_t *modif, const Shift_data_t *data_shift);
CodeError_e Scale_Model_f(Modif_t *modif, const double data_scale);
CodeError_e Rotate_Model_f(Modif_t *modif, const Rotate_data_t *data_rotate);

#endif //_MOD_H_