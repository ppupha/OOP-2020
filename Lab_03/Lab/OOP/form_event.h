#ifndef _form_event_H_
#define _form_event_H_

#include "Constant.h"
#include "FigureInit.h"
#include "DrawInit.h"
#include "ModifInit.h"

enum Action_t 
{
	canvasInit, 
	LoadFigure,  
	ShiftFigure, 
	ScaleFigure, 
	RotateFigure,
	DeleteFigure,
	DrawFigure,
};

Error_t action_process(const Action_t &action, const Form_data_t *fdata);

#endif //_form_event_H_
