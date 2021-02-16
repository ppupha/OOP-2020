#include "figure.h"

void figure_print(Figure *f)
{
	for (int i = 0; i < f->pointNum; i++)
		point_print(f->pointArr + i);
}

Figure * figure_init(int n)
{
	Figure *f = new Figure;
	f->pointNum = n;
	f->pointArr = new Point[f->pointNum];
	return f;
}

void figure_del(Figure *f)
{
	/*
	for (int i = 0; i < f->pointNum; i++)
		point_del(f->pointArr[i]);
	*/
	delete [] f;
}

Figure * figure_file_input(string filename)
{
	ifstream file;
	int col = 3;
	int row = 5;
	double mat[5][3];
	Figure *f = figure_init(row);

	file.open(filename);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			file >> mat[i][j];
		Point *p = point_from_arr(mat[i]);
		point_copy(f->pointArr + i, p);
		point_del(p);
	}

	file.close();
	return f;
}

bool check_coplanar(Point *A, Point *B, Point *C, Point *D)
{
	Vector *vAB = vector_from_point(A, B);
	Vector *vAC = vector_from_point(A, C);
	Vector *nABC = vector_mult(vAB, vAC);
	Vector *vDB = vector_from_point(D, B);
	Vector *vDC = vector_from_point(D, C);
	Vector *nBCD = vector_mult(vDB, vDC);
	Vector *v = vector_mult(nABC, nBCD);
	return vector_is_zero(v);

}

bool figure_check(Figure *f)
{
	if (f->pointNum < 4)
		return false;
	Point *A = f->pointArr + 0;
	Point *B = f->pointArr + 1;
	Point *C = f->pointArr + 2;
	for (int i = 3; i < f->pointNum - 1; i++)
		if (!check_coplanar(A, B, C, f->pointArr + i))
			return false;
	if (check_coplanar(A, B, C, f->pointArr + (f->pointNum - 1)))
		return false;
	return true;
}

void figure_move(Figure *f, double dx, double dy, double dz)
{
	for (int i = 0; i < f->pointNum; i++)
		point_move(f->pointArr + i, dx, dy, dz);
}

void figure_scale(Figure *f, double kx, double ky, double kz, Point *M)
{
	for (int i = 0; i < f->pointNum; i++)
		point_scale(f->pointArr + i, kx, ky, kz, M);
}

void figure_rotate_by_ox(Figure *f,  double angle, double x, double y)
{
	for (int i = 0; i < f->pointNum; i++)
		point_rotate_by_ox(f->pointArr + i, angle, x, y);
}

void figure_rotate_by_oy(Figure *f, double angle, double x, double z)
{
	for (int i = 0; i < f->pointNum; i++)
		point_rotate_by_oy(f->pointArr + i, angle, x, z);
}

void figure_rotate_by_oz(Figure *f, double angle, double x, double y)
{
	for (int i = 0; i < f->pointNum; i++)
		point_rotate_by_oz(f->pointArr + i, angle, x, y);
}
