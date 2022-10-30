#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include "Square.h"
using namespace std;

Square::Square() {
	b.set_x(0);
	b.set_y(0);
	d.set_x(0);
	d.set_y(0);
	diagonal = Segment();
}

Square::~Square() {

}

Square::Square(Point b) {
	this->b = b;
	this->d = Point();
	this->diagonal = Segment(b, d);
}

Square::Square(Point b, Point d) {
	this->b = b;
	this->d = b;
	this->diagonal = Segment(b, d);
}

void Square::set_b(Point i) {
	b = i;
}

void Square::set_d(Point j) {
	d = j;
}

void Square::set_diagonal(Segment r) {
	diagonal = r;
}

Point Square::get_b() {
	return b;
}

Point Square::get_d() {
	return d;
}

Segment Square::get_diagonal() {
	return diagonal;
}

void Square::input() {
	double x, y;
	cout << "������� ���������� ������ ����� ��������� ����� ������:" << endl;
	cin >> x >> y;
	b.set_x(x);
	b.set_y(y);
	cout << "������� ���������� ������ ����� ��������� ����� ������:" << endl;
	cin >> x >> y;
	d.set_x(x);
	d.set_y(y);
	diagonal = Segment(b, d);
}

void Square::output() {
	cout << "���������� ������ ����� ���������: (" << b.get_x() << ", " << b.get_y() << ")" << endl;
	cout << "���������� ������ ����� ���������: (" << d.get_x() << ", " << d.get_y() << ")" << endl;
	cout << "����� ��������� ����� " << diagonal.get_length() << endl;
	cout << "�������� �������� ����� " << square_perimeter() << endl;
	cout << "������� �������� ����� " << square_area() << endl;
}

double Square::square_perimeter() {
	double perimeter;
	perimeter = 2 * sqrt(2) * diagonal.get_length();
	return perimeter;
}

double Square::square_area() {
	double area;
	area = pow(diagonal.get_length(), 2) / 2;
	return area;
}