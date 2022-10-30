#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Point.h"
using namespace std;

Point::Point() {
	x = y = 0;
}

Point::~Point() {

}

Point::Point(double x) {
	this->x = x;
	this->y = 0;
}

Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
}

void Point::set_x(double i) {
	x = i;
}

void Point::set_y(double j) {
	y = j;
}

double Point::get_x() {
	return x;
}

double Point::get_y() {
	return y;
}


void Point::input() {
	cout << "Введите координату x:\n";
	cin >> x;
	cout << "Введите координату y:\n";
	cin >> y;
}

void Point::output() {
	cout << "Координаты точки: (" << x << ", " << y << ")";
}
