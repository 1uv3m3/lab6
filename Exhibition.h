#pragma once
#include<iostream>
#include<string>
#include"Furniture.h"
#include"Chair.h"
#include"ComputerChair.h"

class Exhibition
{
	Furniture** p;
	size_t num;

public:
	Exhibition();

	Exhibition(Furniture** p2, size_t n);

	Exhibition(Exhibition& p2);

	void clear();

	~Exhibition();

	//ввод вывод
	void scan(std::istream& in);

	void print(std::ostream& out);

	//методы
	void price_filter();

	void sizes();
};

//ввод вывод
std::istream& operator>>(std::istream& in, Exhibition obj);

std::ostream& operator<<(std::ostream& out, Exhibition obj);