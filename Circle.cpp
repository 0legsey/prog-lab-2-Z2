#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include "Circle.h"
using namespace std;

Circle::Circle() {
	center.set_x(0);
	center.set_y(0);
	circle_point.set_x(0);
	circle_point.set_y(0);
	radius = Segment();
}

Circle::~Circle() {

}

Circle::Circle(Point center) {
	this->center = center;
	this->circle_point = Point();
	this->radius = Segment(center, circle_point);
}

Circle::Circle(Point center, Point circle_point) {
	this->center = center;
	this->circle_point = circle_point;
	this->radius = Segment(center, circle_point);
}

void Circle::set_center(Point i) {
	center = i;
}

void Circle::set_circle_point(Point j) {
	circle_point = j;
}

void Circle::set_radius(Segment r) {
	radius = r;
}

Point Circle::get_center() {
	return center;
}

Point Circle::get_circle_point() {
	return circle_point;
}

Segment Circle::get_radius() {
	return radius;
}

void Circle::input() {
	double x, y;
	cout << "Введите координаты цента окружности через пробел:" << endl;
	cin >> x >> y;
	center.set_x(x);
	center.set_y(y);
	cout << "Введите координаты точки на окружности через пробел:" << endl;
	cin >> x >> y;
	circle_point.set_x(x);
	circle_point.set_y(y);
	radius = Segment(center, circle_point);
}

void Circle::output() {
	cout << "Координаты цента окружности: (" << center.get_x() << ", " << center.get_y() << ")" << endl;
	cout << "Координаты точки на окружности: (" << circle_point.get_x() << ", " << circle_point.get_y() << ")" << endl;
	cout << "Длина радиуса равна " << radius.get_length() << endl;
	cout << "Длина окружности равна " << circle_length() << endl;
	cout << "Площадь круга равна " << circle_area() << endl;
}

double Circle::circle_length() {
	double len;
	len = 2 * M_PI * radius.get_length();
	return len;
}

double Circle::circle_area() {
	double area;
	area = M_PI * pow(radius.get_length(), 2);
	return area;
}