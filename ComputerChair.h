#pragma once
#include<iostream>
#include"Furniture.h"



class ComputerChair : public Furniture
{
protected:
	bool pads;

public:
	//������������
	ComputerChair();

	//���� �����
	void print(std::ostream& out) const override;

	void scan(std::istream& in) override;


	//������
	std::string MyName() const override;

	Furniture* copy() const override;


};