#pragma once
#include<iostream>
#include"Furniture.h"



class Chair : public Furniture
{
protected:
	bool patterns;
public:
	//������������
	Chair();


	//���� �����
	void print(std::ostream& out) const override;

	void scan(std::istream& in) override;


	//������
	std::string MyName() const override;

	Furniture* copy() const override;
};