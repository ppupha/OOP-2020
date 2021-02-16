#pragma once
#ifndef _EXCEPTION_H_
#define _EXCEPTION_H_
#include <exception>
#include <string.h>
#include<string>
using namespace std;

class ExceptionArray: public std::exception
{
protected:
	string errmsg;
public:
	ExceptionArray(string funcname, string classname, string inf)
	{
		this->errmsg = "\n\tFunction: " + funcname + "\n\tClass: " + classname +  "\n\tErr:" + inf + "\n";
	}

	virtual string what()
	{
		return this->errmsg;
	}
};

class ErrorIndex : public ExceptionArray
{
private:
	string err = "Index Error";
public:
	ErrorIndex(string funcname, string classname, string inf):ExceptionArray(funcname, classname, inf)
	{}

	virtual string what()
	{ 
		return err + errmsg; 
	}
};

class ErrorMult : public ExceptionArray
{
private:
	string err = "Mult Error";
public:
	ErrorMult(string funcname, string classname, string inf) :ExceptionArray(funcname, classname, inf)
	{}
	virtual string what()
	{
		return err + errmsg;
	}
};

class ErrorEmpty : public ExceptionArray
{
private:
	string err = "Empty Error";
public:
	ErrorEmpty(string funcname, string classname, string inf) :ExceptionArray(funcname, classname, inf)
	{}

	virtual string what()
	{
		return err + errmsg;
	}
};

class ErrorSize : public ExceptionArray
{
private:
	string err = "Size Error";
public:
	ErrorSize(string funcname, string classname, string inf) :ExceptionArray(funcname, classname, inf)
	{}

	virtual string what()
	{
		return err + errmsg;
	}
};


class ErrorZeroDet : public ExceptionArray
{
private:
	string err = "Zero Det Error";
public:
	ErrorZeroDet(string funcname, string classname, string inf) :ExceptionArray(funcname, classname, inf)
	{}

	virtual string what()
	{
		return err + errmsg;
	}
};

#endif // !_EXCEPTION_H_
