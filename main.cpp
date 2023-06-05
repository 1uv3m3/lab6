#include<iostream>
#include<fstream>
#include<string>
#include"Exhibition.h"

using namespace std;

enum Menu
{
	scan_from_key,
	scan_from_file,
	print_to_display,
	print_to_file,
	get_price_filter,
	get_sizes,
	exit_programm
};

int main()
{
	system("chcp 1251");
	
	int ans;
	Exhibition b;

	do
	{
		cout << "Выберите пункт меню: " << endl;
		cout << scan_from_key << " - чтение с клавиатуры" << endl
			<< scan_from_file << " - чтение из файла" << endl
			<< print_to_display << " - вывод на экран" << endl
			<< print_to_file << " - вывод в файл" << endl
			<< get_price_filter << " - ценовой фильтр" << endl
			<< get_sizes << " - получить средние, максимальные и минимальные размеры мебели" << endl
			<< exit_programm << " - выход" << endl;
		cin >> ans;

		switch (ans)
		{
		case scan_from_key:
		{
			cin >> b;
			break;
		}
		case scan_from_file:
		{
			string path;
			cout << "Введите название файла: ";
			cin >> path;
			ifstream fin(path + ".txt");
			fin >> b;
			fin.close();
			break;
		}
		case print_to_display:
		{
			cout << b;
			break;
		}
		case print_to_file:
		{
			string path;
			cout << "Введите название файла: ";
			cin >> path;
			ofstream fout(path + ".txt");
			fout << b;
			fout.close();
			break;
		}
		case get_price_filter:
		{
			b.price_filter();
			break;
		}
		case get_sizes:
		{
			b.sizes();
			break;
		}
		case exit_programm:
		{
			b.clear();
			break;
		}
		}
	}
	while (ans != exit_programm);


	return 0;
}