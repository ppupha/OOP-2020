#include "stdafx.h"


#if 0
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <fstream>

#include "figure.h"
#include "define.h"

#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;


void figure_proc(Figure *f, int id)
{
	switch (id)
	{
	case DRAW: // Draw
		break;
	case MOVE: // Move
		break;
	case SCALE: // Scale
		break;
	case ROTATE: // Rotate
		break;
	default:
		break;
	}
}

#endif
#if 0
int main()
{
	cout << "Hello World" << endl;

	Figure *f = figure_file_input("inp.txt");
	
	figure_print(f);
	
	figure_del(f);

	system("pause");
	return 0;
}

#endif
