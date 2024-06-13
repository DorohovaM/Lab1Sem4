#pragma once
#include <iostream>
using namespace std;

class Point
{
	double x, y;
	
public:

	Point();
	Point(double x0, double y0);

	bool on_straight_line(double k, double b);
	bool above_straight_line(double k, double b);
	bool under_straight_line(double k, double b);
	int coord_quarter();

	bool operator==(Point& point0);
	bool operator!=(Point& point0);

	friend ostream& operator<<(ostream& os, const Point& point0);
	friend istream& operator>>(istream& is, Point& point0);
};

Point::Point() {
	x = y = 0;
}
Point::Point(double x0, double y0) {
	x = x0;
	y = y0;
}

bool Point::operator==(Point& point0) {

	if (x == point0.x && y == point0.y)
		return true;
	return false;
}

bool Point::operator!=(Point& point0) {

	if (x != point0.x || y != point0.y)
		return true;
	return false;
}

bool Point::on_straight_line(double k, double b) {

	if ((k * x + b) == y)
		return true;
	return false;
}

bool Point::above_straight_line(double k, double b) {

	if ((k * x + b) < y)
		return true;
	return false;
}

bool Point::under_straight_line(double k, double b) {

	if ((k * x + b) > y)
		return true;
	return false;
}

int Point::coord_quarter() {

	int quarter = 0;
	if (x > 0 && y > 0)
		quarter = 1;
	else if (x < 0 && y > 0)
		quarter = 2;
	else if (x < 0 && y < 0) 
		quarter = 3;
	else if (x > 0 && y < 0) 
		quarter = 4;
	return quarter;

}

ostream& operator<<(ostream& os, const Point& point0) {

	os << "Coordinate Points: (" << point0.x << ", " << point0.y << ")" << endl;
	return os;
}

istream& operator>>(istream& is, Point& point0) {

	is >> point0.x >> point0.y;
	return is;
};

