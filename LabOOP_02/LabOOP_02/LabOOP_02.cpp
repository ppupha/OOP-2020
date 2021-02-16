// LabOOP_02.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#include "Matrix.h"
#include "Exception.h"


int main()
{
	try
	{
		cout << "Hello World!!!" << endl;
		cout << "Int Matrix: " << endl;
		Matrix<double> a = { {9.0, 19.0, 8.0}, {9.0, 8.0, 7.0}, {8.0, 7.0, 6.0} };
		Matrix<double> b(a);
		cout << "Input Matrix A: " << endl;
		cout << "Matrix A" << endl;
		cout << a;
		cout << "Matrix A" << endl;
		cout << b;

		Matrix<double> c = a + b;
		cout << "Matrix C" << endl;
		Matrix<double> d(a);
		d *= 2;
		
		cout << "Matrix D:" << endl;
		cout << d;
		cout << c << (c^2) << (a * b) << ((a + b)^0) << ((d+c)^-1);
		a = d * 2;
		cout << a;
		const Matrix<double> e(a);
		cout << e;

		Iter<double> it = a.end();
		it = it - 5;
		it++;
		cout << *it << endl;
	}
	catch (ExceptionArray& err)
	{
		cout << err.what() << endl;
	}
	catch (exception& err)
	{
		cout << "Error:"<< err.what() << endl;
	}
	catch (...)
	{
		cout << "Undefined Error" << endl;
	}
	return 0;

}

	

