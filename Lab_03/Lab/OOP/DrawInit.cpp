#include "stdafx.h"
#include "DrawInit.h"

Easel_t init_easel(const wrapper_canvas *canva)
{
	Easel_t easel;
	easel.canvas = canva->pb->CreateGraphics(); 
	easel.backcolor = canva->pb->BackColor;	 
	easel.centre.x = canva->pb->Width/2;		 
	easel.centre.y = canva->pb->Height/2;		  
	return easel;
}

