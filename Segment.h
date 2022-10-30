#pragma once
#include <iostream>
#include "Point.h"

class Segment {
public:
	Segment();
	~Segment();
	Segment(Point a);
	Segment(Point a, Point b);
	void input();
	void output();
	void set_a(Point i);
	void set_b(Point j);
	void set_length(double l);
	Point get_a();
	Point get_b();
	double get_length();
	double length_calc();
private:
	double length;
	Point a;
	Point b;
};