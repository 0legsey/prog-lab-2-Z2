#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include "Segment.h"
using namespace std;

Segment::Segment() {
	a.set_x(0);
	a.set_y(0);
	b.set_x(0);
	b.set_y(0);
	length = 0;
}

Segment::~Segment() {

}

Segment::Segment(Point a) {
	this->a = a;
	this->b = Point();
	this->length = length_calc();
}

Segment::Segment(Point a, Point b) {
	this->a = a;
	this->b = b;
	this->length = length_calc();
}

void Segment::set_a(Point i) {
	a = i;
}

void Segment::set_b(Point j) {
	b = j;
}

void Segment::set_length(double l) {
	length = l;
}

Point Segment::get_a() {
	return a;
}

Point Segment::get_b() {
	return b;
}

double Segment::get_length() {
	return length;
}

void Segment::input() {
	double x, y;
	cout << "Введите координаты первой точки через пробел:" << endl;
	cin >> x >> y;
	a.set_x(x);
	a.set_y(y);
	cout << "Введите координаты второй точки через пробел:" << endl;
	cin >> x >> y;
	b.set_x(x);
	b.set_y(y);
	length = length_calc();
}

void Segment::output() {
	cout << "Координаты первой точки: (" << a.get_x() << ", " << a.get_y() << ")" << endl;
	cout << "Координаты второй точки: (" << b.get_x() << ", " << b.get_y() << ")" << endl;
	cout << "Длина отрезка равна " << length;
}

double Segment::length_calc() {
	double len;
	len = pow(a.get_x() - b.get_x(), 2) + pow(a.get_y() - b.get_y(), 2);
	return sqrt(len);
}