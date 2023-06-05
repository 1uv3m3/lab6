#pragma once

#include<iostream>
#include<string>
#include"dimensions.h"


class Furniture
{
protected:
	std::string name;
	size_t price;
	dimensions size;
public:
	//конструкторы
	Furniture();
	virtual Furniture* copy() const = 0;
	virtual ~Furniture() {}

	virtual void operator=(Furniture* p);

	//ввод вывод
	virtual void print(std::ostream& out) const;

	virtual void scan(std::istream& in);

	//методы
	size_t get_price() const;

	dimensions get_size() const;

	virtual std::string MyName() const;


};


//ввод вывод
std::ostream& operator<<(std::ostream& out, const Furniture& b);

std::istream& operator>>(std::istream& in, Furniture& b);