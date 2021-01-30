#include "Point.h"

Point::Point(int x, int y, int a, int b)
{
	this->x = x;
	this->y = y;
	this->a = a;
	this->b = b;
	if (std::pow(this->y, 2) != (std::pow(this->x, 3) + this->a * this->x + b))
	{
		string message = "(" + std::to_string(x) + " " + std::to_string(y) + ")" + " is not on the curve.";
		Error error(Error::ErrorTypes::ERROR, message);

		Tools::write_error(error);
	}
}

bool Point::operator == (Point* point)
{
	return x == point->x && y == point->y && a == point->a && b == point->b;
}
bool Point::operator != (Point* point) 
{
	return x != point->x || y != point->y || a != point->a || b != point->b;
}
string Point::toString()
{
	string message;
	
	if (x == NULL)
	{
		message = "Point(infinity)";
	}
	else
	{
		message = "Point (" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(a) + ", " + std::to_string(b) + ")";
	}
	return message;
}
Point Point::operator + (Point* point)
{
	Point  *new_point{};
	if (a != point->a || b != point->b)
	{
		
		string message = "Points " + this->toString() + ", " + point->toString() + " arenot on the same curve";
		Error error(Error::ErrorTypes::ERROR, message);

		Tools::write_error(error);
	}

	if (x == NULL)
	{
		new_point = point;
	}
	else if (point->x == NULL)
	{
		new_point = this;
	}
	else if (x == point->x && y == point->y)
	{
		Point pointer(0, 0, a, b);
		new_point = &pointer;
	}
	else if (x != point->x)
	{
		double s = (point->y - y) / (point->x - x);
		double x = std::pow(s, 2) - this->x - point->x;
		double y = s * (this->x - x) - this->y;
		Point pointer(x, y, a, b);
		new_point = &pointer;
	}
	else if (this == point && y == 0 * x)
	{
		Point pointer(0, 0, a, b);
		new_point = &pointer;
	}
	else if (this == point)
	{
		double s = (3 * std::pow(x,2) + a) / (2 * y);
		double x = std::pow(s, 2) - 2 - this->y;
		double y = s * (this->x - x) - this->y;
		Point pointer(x, y, a, b);
		new_point = &pointer;
	}

	return *new_point;
} 