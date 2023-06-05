#include "dimensions.h"
#include"Furniture.h"
#include"Chair.h"
#include"ComputerChair.h"
#include"Exhibition.h"


//операции
dimensions& operator+(const dimensions& p1, const dimensions& p2)
{
	dimensions sum = set(0);
	sum.height = p1.height + p2.height;
	sum.width = p1.width + p2.width;
	sum.length = p1.length + p2.length;
	return sum;
}

bool operator<(const dimensions& p1, const dimensions& p2)
{
	return volume(p1) < volume(p2);
}

bool operator>(const dimensions& p1, const dimensions& p2)
{
	return volume(p1) > volume(p2);
}


//функции
dimensions& set(const double x)
{
	dimensions t;
	t.height = x;
	t.length = x;
	t.width = x;
	return t;
}

double&& volume(const dimensions& p)
{
	return p.height * p.length * p.width;
}

dimensions min(const dimensions& p1, const dimensions& p2)
{
	if (p1 < p2)
		return p1;
	else
		return p2;
}

dimensions max(const dimensions& p1, const dimensions& p2)
{
	if (p1 > p2)
		return p1;
	else
		return p2;
}


//ввод вывод
std::istream& operator>>(std::istream& in, dimensions& p)
{
	in >> p.length >> p.width >> p.height;
	return in;
}

std::ostream& operator<<(std::ostream& out, dimensions&& p)
{
	out << p.length << "x" << p.width << "x" << p.height;
	return out;
}






//конструкторы
Furniture::Furniture()
{
	name = "";
	price = 0;
	size = set(0);
}

void Furniture::operator=(Furniture* p)
{
	name = p->name;
	price = p->price;
	size = p->size;
}

//ввод вывод
void Furniture::print(std::ostream& out) const
{
	out << name << " цена: " << price << " габариты: "
		<< &size << std::endl;
}
void Furniture::scan(std::istream& in)
{
	if (&std::cin == &in)
		std::cout << "¬ведите название товара, цену и габариты (длину, ширину, высоту): ";
	in >> name >> price >> size;
}

//методы
size_t Furniture::get_price() const
{
	return price;
}

dimensions Furniture::get_size() const
{
	return size;
}

std::string Furniture::MyName() const
{
	return "Furniture";
}


//ввод вывод
std::ostream& operator<<(std::ostream& out, const Furniture& b)
{
	b.print(out);
	return out;
}

std::istream& operator>>(std::istream& in, Furniture& b)
{
	b.scan(in);
	return in;
}






//конструкторы
Chair::Chair()
{
	patterns = false;
}


//ввод вывод
void Chair::print(std::ostream& out) const
{
	Furniture::print(out);
	if (patterns == true)
		out << "узоры есть" << "\n";
	else if (patterns == false)
		out << "узоров нет" << "\n";
}

void Chair::scan(std::istream& in)
{
	Furniture::scan(in);
	if (&std::cin == &in)
		std::cout << "есть ли узоры? ";
	std::string t;
	in >> t;
	if (t == "нет")
		patterns = false;
	else
		patterns = true;
}


//методы
std::string Chair::MyName() const
{
	return "Chair";
}

Furniture* Chair::copy() const
{
	Chair t;
	t = *this;
	return &t;
}






//конструкторы
ComputerChair::ComputerChair()
{
	pads = false;
}

//ввод вывод
void ComputerChair::print(std::ostream& out) const
{
	Furniture::print(out);
	if (pads == true)
		out << "подушечки есть" << "\n";
	else if (pads == false)
		out << "подушечек нет" << "\n";
}

void ComputerChair::scan(std::istream& in)
{
	Furniture::scan(in);
	if (&std::cin == &in)
		std::cout << "есть ли подушечки? ";
	std::string t;
	in >> t;
	if (t == "нет")
		pads = false;
	else
		pads = true;
}


//методы
std::string ComputerChair::MyName() const
{
	return "ComputerChair";
}

Furniture* ComputerChair::copy() const
{
	ComputerChair t;
	t = *this;
	return &t;
}






//конструкторы
Exhibition::Exhibition()
	{
		p = nullptr;
		num = 0;
	}

Exhibition::Exhibition(Furniture** p2, size_t n)
		: p(p2), num(n)
	{ }

Exhibition::Exhibition (Exhibition& p2)
		: Exhibition(p2.p, p2.num)
	{ }

	void Exhibition::clear()
	{
		for (size_t i = 0; i < num; i++)
			delete p[i];
		delete[]p;
		p = nullptr;
		num = 0;
	}

	Exhibition::~Exhibition ()
	{
		clear();
	}

	//ввод вывод
	void Exhibition::scan (std::istream& in)
	{
		if (p != nullptr)
			clear();
		if (&in == &std::cin)
			std::cout << "введите количество товаров: ";
		in >> num;
		Furniture** arr = new Furniture * [num];
		for (size_t i = 0; i < num; i++)
		{
			if (&in == &std::cin)
				std::cout << "введите тип мебели: ";
			std::string type;
			in >> type;
			if (type == "Ch")
			{
				arr[i] = new Chair;
			}
			else if (type == "CCh")
			{
				arr[i] = new ComputerChair;
			}
			(*arr[i]).scan(in);
		}
		p = arr;
	}

	void Exhibition::print(std::ostream& out)
	{
		out << num << std::endl;
		for (size_t i = 0; i < num; i++)
		{
			p[i]->print(out);
		}
	}

	//методы
	void Exhibition::price_filter()
	{
		size_t min, max;
		std::cout << "введите минимальное и максимальное значени€ цен: ";
		std::cin >> min >> max;
		for (size_t i = 0; i < num; i++)
			if (p[i]->get_price() <= max && p[i]->get_price() >= min)
				p[i]->print(std::cout);
	}

	void Exhibition::sizes()
	{
		dimensions average = set(0);
		dimensions min_size = set(10000.0);
		dimensions max_size = set(0.0);
		
		
		for (size_t i = 0; i < num; i++)
		{
			average = average + p[i]->get_size();
			min_size = min(min_size, p[i]->get_size());
			max_size = max(max_size, p[i]->get_size());
		}

		std::cout << "средние габариты: " << &average << std::endl;
		std::cout << "минимальные габариты: " << &min_size << std::endl;
		std::cout << "максимальные габариты: " << &max_size << std::endl;

	}

//ввод вывод
std::istream& operator>>(std::istream& in, Exhibition obj)
{
	obj.scan(in);
	return in;
}

std::ostream& operator<<(std::ostream& out, Exhibition obj)
{
	obj.print(out);
	return out;
}