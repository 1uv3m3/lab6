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

	//���� �����
	void scan(std::istream& in);

	void print(std::ostream& out);

	//������
	void price_filter();

	void sizes();
};

//���� �����
std::istream& operator>>(std::istream& in, Exhibition obj);

std::ostream& operator<<(std::ostream& out, Exhibition obj);