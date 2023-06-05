#pragma once
#include<iostream>


struct dimensions
{
	double height;
	double width;
	double length;
};


//операции
dimensions& operator+(const dimensions& p1, const dimensions& p2);

bool operator<(const dimensions& p1, const dimensions& p2);

bool operator>(const dimensions& p1, const dimensions& p2);


//функции
dimensions& set(const double x);

double&& volume(const dimensions& p);

dimensions min(const dimensions& p1, const dimensions& p2);

dimensions max(const dimensions& p1, const dimensions& p2);


//ввод вывод
std::istream& operator>>(std::istream& in, dimensions& p);

std::ostream& operator<<(std::ostream& out, dimensions&& p);