#pragma once
#include<iostream>
#include"Furniture.h"



class ComputerChair : public Furniture
{
protected:
	bool pads;

public:
	//конструкторы
	ComputerChair();

	//ввод вывод
	void print(std::ostream& out) const override;

	void scan(std::istream& in) override;


	//методы
	std::string MyName() const override;

	Furniture* copy() const override;


};