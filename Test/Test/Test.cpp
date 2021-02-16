// Test.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#if 0

class A
{
public:
	A() {
		cout << "A\n";
	}
	void Draw() { cout << "Draw A\n"; }

	~A()
	{
		cout << "Delete A" << endl;
	}
};

class B: public A
{
public:
	B()
	{
		cout << "B\n";
	}

	void Draw() { cout << "Draw B\n"; }

	~B()
	{
		cout << "Delete B" << endl;
	}
};

class C : public B
{
public:
	C() {
		cout << "C\n";
	}

	void Draw() { cout << "Draw C\n"; }

	~C()
	{
		cout << "Delete C" << endl;
	}
};

class D : public C
{
public:
	D()
	{
		cout << "D\n";
	}

	void Draw() { cout << "Draw D\n"; }
	~D()
	{
		cout << "Delete D" << endl;
	}
};


int main()
{
	cout << "Hello World!!!\n";
	C *obj = new D;
	obj->Draw();
	delete obj;
    return 0;
}

#endif

