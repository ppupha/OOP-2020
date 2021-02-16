#include "stdafx.h"
#include "form_event.h"
#include "FigureDraw.h"
#include "FigureLoadFile.h"
#include "FigureDelete.h"
#include "FigureModif.h"
#include "ModifInit.h"

/* 
 *  Form Event
 return rc
 */
Error_t action_process(const Action_t &action, const Form_data_t *fdata)
{
    Error_t rc = OK;                                     
    static Figure_t figure = init_figure();                

    switch(action)
    {
        case LoadFigure:                                     
			rc = figure_load(&figure, fdata->filename);
			break;
        case ShiftFigure:                                    
			rc = figure_shift(&figure, &(fdata->data_shift));
			break;
        case ScaleFigure:                                    
			rc = figure_scale(&figure, &(fdata->data_scale));
			break;
        case RotateFigure:                                  
			rc = figure_rotate(&figure, &(fdata->data_rotate));
			break;
		case DrawFigure:
			rc = figure_draw(&figure, fdata->canva);
			break;
        case DeleteFigure:                                   
            rc = figure_delete(&figure);
			break;
        default:                                           
            rc = ERROR_ACTION;
    }
    
    return rc;
}