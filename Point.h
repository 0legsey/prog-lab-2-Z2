#pragma once
#include <iostream>

class Point {
public:
	Point();
	~Point();
	Point(double x);
	Point(double x, double y);
	void input();
	void output();
	void set_x(double i);
	void set_y(double j);
	double get_x();
	double get_y();
private:
	double x;
	double y;
};