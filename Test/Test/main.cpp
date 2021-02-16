#include "stdafx.h"
#include <iostream>
using namespace std;

class A
{
public:
	A() { cout << "A Create" << endl; }
	~A(){ { cout << "A Destroy" << endl; } }
};

class B
{
public:
	B(char *s) { cout << "B Createter----" << endl; }
	~B() { { cout << "B Destroy" << endl; } }
};

class D
{
public:
	D() { cout << "D Create" << endl; }
	~D() { { cout << "D Destroy" << endl; } }
};



class C: public B, virtual public D, virtual public A
{
public:
	C() : B("123") { cout << "C Create" << endl; }
	~C() { { cout << "C Destroy" << endl; } }
};


int main()
{
	C o;
	return 0;
}

