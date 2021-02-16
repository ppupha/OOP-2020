
#if 1

#include <memory>

#include <iostream>
using namespace std;
#include <stdlib.h>

enum STATE_ID{
	SHIFTSTATE,
	ROTATESTATE,
	SCALESTATE,
	DRAWSTATE,
	LOADSTATE,
};

class BaseData
{
private:
	double byX;
	double byY;
	double byZ;
public:
	BaseData() = default;
	void setX(double x) { this->byX = x; }
	void setY(double y) { this->byY = y; }
	void setZ(double z) { this->byZ = z; }
	double getX() { return this->byX; }
	double getY() { return this->byY; }
	double getZ() { return this->byZ; }
};

class Point;

class PointState {
protected:
	shared_ptr<Point> point;
	shared_ptr<BaseData> modifdata;
public:
	PointState() = default;
	void handleRequest(BaseData data);
	//...
};

class pointShiftState: public PointState 
{
public:
	void handleRequest(BaseData &data)
	{
		cout << "Call pointShiftState" << endl;
	}

};

class pointRotateState : public PointState
{
public:
	void handleRequest(BaseData &data)
	{
		cout << "Call pointRotateState" << endl;
	}
};

class pointScaleState : public PointState
{
public:
	void handleRequest(BaseData &data)
	{
		cout << "Call pointScaleState" << endl;
	}

};

class Point
{
private:
	BaseData data;
	PointState pstate;
public:

	void setState(PointState state) { this->pstate = state; }

	void applyState() { (this->pstate).handleRequest(this->data); }

	BaseData getData() { return this->data; }

	void setData(BaseData data) { this->data = data; }
};

class FigureState
{
public:
	virtual void handleRequest() {};
};


class FigureShiftState : public FigureState
{
private:
public:
	void handleRequest()
	{
		cout << "FigureShiftState -> handleRequest" << endl;
	}
};

class FigureScaleState : public FigureState
{
	void handleRequest()
	{
		cout << "FigureScaleState -> handleRequest" << endl;
	}
};

class FigureRotateState : public FigureState
{
	void handleRequest()
	{
		cout << "FigureRotateState -> handleRequest" << endl;
	}
};

class FigureDrawState : public FigureState
{
private:
	char* filename;

public:
	void handleRequest()
	{
		cout << "FigureDrawState -> handleRequest" << endl;
	}
};

class FigureReadState : public FigureState
{
	void handleRequest()
	{
		cout << "FigureReadState -> HandleRequest" << endl;
	}
};

// Figure Context
class Figure
{
private:
	int pointNum = 0;
	shared_ptr<Point[]> pointArr;
	shared_ptr<shared_ptr<int[]>[]> matrix;
	FigureState* state;

public:
	void setState(FigureState* state) { this->state = state; };
	void applyState() { this->state->handleRequest(); }
	void setState(int state_id)
	{
		switch (state_id)
		{
		case SHIFTSTATE:
			this->state = new FigureShiftState();
			break;
		case SCALESTATE:
			this->state = new FigureScaleState();
			break;
		default:
			this->state = new FigureDrawState();
		}
	}
};



int main()
{
	cout << "Hello World" << endl;

	Figure fig;
	
	fig.setState(SHIFTSTATE);
	fig.applyState();
	return 0;
}

#endif