#pragma once
#include "Tools.h"
#include "Error.h"
using namespace std;
class Point
{
	private:
		int x;
		int y;
		int a;
		int b;
	public:
		Point(int x, int y, int a, int b);

		bool operator == (Point* point);
		bool operator != (Point* point);
		string toString();
		Point operator + (Point* point);

};

