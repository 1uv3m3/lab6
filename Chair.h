#pragma once
#include<iostream>
#include"Furniture.h"



class Chair : public Furniture
{
protected:
	bool patterns;
public:
	//конструкторы
	Chair();


	//ввод вывод
	void print(std::ostream& out) const override;

	void scan(std::istream& in) override;


	//методы
	std::string MyName() const override;

	Furniture* copy() const override;
};