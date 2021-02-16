

#if 0

#include "gl/glut.h"
static GLfloat spin = 0.0; /* góc quay hiện tại của hình chữ nhật */

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0); /* xoay một góc spin quanh trục z */
	glColor3f(1.0, 1.0, 1.0); /* thiết lập màu vẽ cho hcn (màu trắng) */
	glRectf(-25.0, -25.0, 25.0, 25.0); /* vẽ hcn */
	glPopMatrix();
	glutSwapBuffers(); /* thực hiện việc hoán đổi 2 buffer */
}
void spinDisplay(void)
{
	spin = spin + 2.0; /* xoay thêm 2 deg cho mỗi lần lặp */
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay(); /* thông báo cho chương trình rằng: cần phải thực
						 hiện việc vẽ lại */
}
/* các thao tác cần làm khi cửa sổ bị thay đổi kích thước */
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); /* thay đổi viewport */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
/* các thao tác xử lý chuột */
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON: /* khi nhấn chuột trái */
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay); /* khi chương trình đang trong trạng
									   thái idle (không phải xử lý gì cả) thì sẽ thực hiện hàm spinDisplay */
		break;
	case GLUT_MIDDLE_BUTTON: /* khi nhấn nút giữa */
		if (state == GLUT_DOWN)
			glutIdleFunc(nullptr);
		break;
	default:
		break;
	}
}
/* hàm main của chương trình */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); /* khai báo việc sử dụng
												 chế độ double buffer */
	glutInitWindowSize(250, 250);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("spinning rectangle");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape); /* đăng ký hàm reshape cho sự kiện cửa sổ bị
							  thay đổi kích thước */
	glutMouseFunc(mouse); /* đăng ký hàm mouse cho sự kiện về chuột */
	glutMainLoop();
	return 0;
}


#elif 0

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <fstream>
#include "gl\glut.h"

#include "figure.h"
#include "points.h"
#include "vectors.h"
#include "defie.h"

#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;


static GLfloat spin = 0.0; /* góc quay hiện tại của hình chữ nhật */

void init(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_FLAT);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(spin, 0.0, 0.0, 1.0); /* xoay một góc spin quanh trục z */
	glColor3f(1.0, 1.0, 1.0); /* thiết lập màu vẽ cho hcn (màu trắng) */
	glRectf(-25.0, -25.0, 25.0, 25.0); /* vẽ hcn */
	glPopMatrix();
	glutSwapBuffers(); /* thực hiện việc hoán đổi 2 buffer */
}
void spinDisplay(void)
{
	spin = spin + 1.0; /* xoay thêm 2 deg cho mỗi lần lặp */
	if (spin > 360.0)
		spin = spin - 360.0;
	glutPostRedisplay(); /* thông báo cho chương trình rằng: cần phải thực
						 hiện việc vẽ lại */
}
/* các thao tác cần làm khi cửa sổ bị thay đổi kích thước */
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h); /* thay đổi viewport */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
/* các thao tác xử lý chuột */
void mouse(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON: /* khi nhấn chuột trái */
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay); /* khi chương trình đang trong trạng
									   thái idle (không phải xử lý gì cả) thì sẽ thực hiện hàm spinDisplay */
		break;
	case GLUT_MIDDLE_BUTTON: /* khi nhấn nút giữa */
		if (state == GLUT_DOWN)
			glutIdleFunc(nullptr);
		break;
	default:
		break;
	}
}

/*
|a b|
|c d| = ad - bc
*/
double delta(double a, double b, double c, double d)
{
	return a * d - b * c;
}

class Point
{
	friend class Vector;
private:
	double x;
	double y;
	double z;
public:
	Point()
	{
		x = 0;
		y = 0;
		z = 0;
	}
	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	Point(double arr[3])
	{
		x = arr[0];
		y = arr[1];
		z = arr[2];
	}

	void print()
	{
		cout << x << " " << y << " " << z << endl;
	}

	void move(double dx, double dy, double dz)
	{
		this->x += dx;
		this->y += dy;
		this->z += dz;
	}

	void scale(double kx, double ky, double kz, Point M)
	{
		this->x = kx * this->x + (1 - kx) * M.x;
		this->y = ky * this->y + (1 - ky) * M.y;
		this->z = kz * this->z + (1 - kz) * M.z;
	}

	void rotate(double angle, double x, double y)
	{

	}

	/*
	quay theo truc Oz
	toạ đô x và y thay đổi
	*/
	void rotate_by_oz(double angle = 45, double x = 0, double y = 0)
	{
		double x0 = this->x;
		double y0 = this->y;
		angle = angle * M_PI / 180;
		this->x = x + (x0 - x) * cos(angle) + (y0 - y) * sin(angle);
		this->y = y - (x0 - x) * sin(angle) + (y0 - y) * cos(angle);
	}
	void rotate_by_oy(double angle = 45, double x = 0, double z = 0)
	{

	}

	void rotate_by_ox(double angle = 45, double x = 0, double y = 0)
	{

	}
};

class Vector
{

private:
	double x;
	double y;
	double z;
public:

	Vector(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector(double a1[3], double a2[3])
	{
		x = a2[0] - a1[0];
		y = a2[1] - a1[1];
		z = a2[2] - a1[2];
	}

	Vector(Point A, Point B)
	{
		this->x = B.x - A.x;
		this->y = B.y - A.y;
		this->z = B.z - A.z;
	}

	Vector mult_vector(Vector v)
	{
		double x = delta(this->y, this->z, v.y, v.z);
		double y = -delta(this->x, this->z, v.x, v.z);
		double z = delta(this->x, this->y, v.x, v.y);
		Vector new_vec{ x, y, z };
		return new_vec;
	}

	void vector_print()
	{
		cout << this->x << " " << this->y << " " << this->z << endl;
	}
	bool is_zero()
	{
		if (x == 0 && y == 0 && z == 0)
			return true;
		else
			return false;
	}
};

class Figure
{
private:
	int n = 5;
	Point Data[5];



public:
	Figure()
	{
		for (int i = 0; i < n; i++)
			this->Data[i] = Point();
	}

	void point_print()
	{
		for (int i = 0; i < n; i++)
			Data[i].print();
	}
	int read_file(string filename)
	{
		ifstream file;
		int col = 3;
		int row = 5;
		double mat[5][3];
		file.open(filename);

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				file >> mat[i][j];
			this->Data[i] = Point(mat[i]);
		}

		file.close();
		return 0;
	}

	bool check_data()
	{

		Point A = Data[0];
		Point B = Data[1];
		Point C = Data[2];
		Point D = Data[3];
		Point S = Data[4];
		Vector AB{ A, B };
		Vector AC{ A, C };
		Vector nABC = AB.mult_vector(AC);
		Vector DB{ D, B };
		Vector DC{ D, C };
		Vector nBCD = DB.mult_vector(DC);
		if (!nABC.mult_vector(nBCD).is_zero())
		{
			cout << "Day khong dong phang" << endl;
			return false;
		}
		Vector SB{ S, B };
		Vector SC{ S, C };
		Vector nSBC = SB.mult_vector(SC);
		if (nABC.mult_vector(nSBC).is_zero())
		{
			cout << "S in ABCD" << endl;
			return false;
		}
		return true;
	}

	void move(double dx, double dy, double dz)
	{
		for (int i = 0; i < 5; i++)
			Data[i].move(dx, dy, dz);
	}

	void scale(double kx, double ky, double kz, Point M)
	{
		for (int i = 0; i < 5; i++)
			Data[i].scale(kx, ky, kz, M);
	}

	void rotate_by_ox(double angle, double x, double y)
	{
		for (int i = 0; i < 5; i++)
			Data[i].rotate_by_ox(angle, x, y);
	}
	void rotate_by_oy(double angle = 45.0, double x = 0.0, double z = 0.0)
	{
		for (int i = 0; i < 5; i++)
			Data[i].rotate_by_oy(angle, x, z);
	}

	void rotate_by_oz(double angle = 45.0, double x = 0.0, double y = 0.0)
	{
		for (int i = 0; i < 5; i++)
			Data[i].rotate_by_oz(angle, x, y);
	}

	void draw()
	{
		glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); /* khai báo việc sử dụng
													 chế độ double buffer */
		glutInitWindowSize(250, 250);
		glutInitWindowPosition(100, 100);
		glutCreateWindow("spinning rectangle");
		init();
		glutDisplayFunc(display);
		glutReshapeFunc(reshape); /* đăng ký hàm reshape cho sự kiện cửa sổ bị
								  thay đổi kích thước */
		glutMouseFunc(mouse); /* đăng ký hàm mouse cho sự kiện về chuột */
		glutMainLoop();
	}
};

void out_matrix(double mat[][3], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << mat[i][j] << " ";
		cout << endl;
	}
}


int read_file(string filename, Point P[5])
{
	ifstream file;
	int col = 3;
	int row = 5;
	double mat[5][3];
	file.open(filename);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			file >> mat[i][j];
		P[i] = Point(mat[i]);
	}

	out_matrix(mat, row, col);


	file.close();
	return 0;
}

bool check_data(Point P[5])
{
	/*Point A{ mat[0] };
	Point B{ mat[1] };
	Point C{ mat[2] };
	Point D{ mat[3] };
	Point S{ mat[4] };*/
	Point A = P[0];
	Point B = P[1];
	Point C = P[2];
	Point D = P[3];
	Point S = P[4];
	Vector AB{ A, B };
	Vector AC{ A, C };
	Vector nABC = AB.mult_vector(AC);
	Vector DB{ D, B };
	Vector DC{ D, C };
	Vector nBCD = DB.mult_vector(DC);
	if (!nABC.mult_vector(nBCD).is_zero())
	{
		cout << "Day khong dong phang" << endl;
		return false;
	}
	Vector SB{ S, B };
	Vector SC{ S, C };
	Vector nSBC = SB.mult_vector(SC);
	if (nABC.mult_vector(nSBC).is_zero())
	{
		cout << "S in ABCD" << endl;
		return false;
	}
	return true;
}

int main1()
{
	cout << "Hello World" << endl;
	Point  P[5];
	read_file("inp.txt", P);
	if (check_data(P))
	{
		cout << "Check Data OK\n";
	}
	else
	{
		cout << "check Data Fail\n";
	}

	cout << "************************************************************************\n";

	Figure fig = Figure();
	fig.read_file("inp.txt");
	if (fig.check_data())
		cout << "Check Data OK\n";
	else
		cout << "check data Fail\n";
	fig.point_print();
	//fig.draw();
	cout << endl;
	fig.rotate_by_oz(90, 0, 0);
	fig.point_print();
	fig.move(10, 5, -5);
	fig.point_print();
	cout << "Finish" << endl;
	system("pause");
	return 0;
}

#endif
