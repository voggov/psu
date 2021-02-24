// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//


#include <cassert>
#include <iostream>
#include <string>
#include <locale>
#include <iomanip>

using namespace std;

class Train
{
private:
	string point;
	int num;
	double _time;
	int places;
	int cupe;
	int plac;

public:
	Train(string point1 = "noname", int num1 = 0, double _time1 = 00.00, int places1 = 0, int cupe1 = 0, int plac1 = 0) :
		point(point1), num(num1), _time(_time1), places(places1), cupe(cupe1), plac(plac1)
	{
		point1 = point;
		num1 = num;
		_time1 = _time;
		places1 = places;
		cupe1 = cupe;
		plac1 = plac;
	}


	void Print()
	{
		cout << "Пункт назначения:" << setw(17) << point << endl;
		cout << "Номер поезда:" << setw(20) << num << endl;
		cout << "Время отправления:" << setw(16) << _time << endl;
		cout << "Количество мест:" << setw(17) << places << endl;
		cout << "Количество мест купе:"<< setw(12) << cupe << endl;
		cout << "Количество мест плацкарт:" << setw(8) << plac << endl<<endl<<endl;

	}

	string Get_point()
	{
		return point;
	}
	int Get_num()
	{
		return num;
	}
	double Get__time()
	{
		return _time;
	}
	int Get_places()
	{
		return places;
	}
	int Get_cupe()
	{
		return cupe;
	}
	int Get_plac()
	{
		return plac;
	}


	void Set_point(string value_point)
	{
		point = value_point;
	}
	void Set_num(int value_num)
	{
		num = value_num;
	}
	void Set__time(double value__time)
	{
		_time = value__time;
	}
	void Set_places(int value_places)
	{
		places = value_places;
	}
	void Set_cupe(int value_cupe)
	{
		cupe = value_cupe;
	}
	void Set_plac(int value_plac)
	{
		plac = value_plac;
	}
	
};

int main()
{
	setlocale(LC_ALL, "ru");
	const int SIZE_ARR = 2;

	Train Sura;
	Sura.Set_point("Penza");
	Sura.Set_num(226);
	Sura.Set__time(01.22);
	Sura.Set_places(70);
	Sura.Set_cupe(102);
	Sura.Set_plac(148);
	cout << "Сура" << endl << endl;
	Sura.Print();

	Train Poezd14;
	Poezd14.Set_point("Perm");
	Poezd14.Set_num(14);
	Poezd14.Set__time(14.15);
	Poezd14.Set_places(85);
	Poezd14.Set_cupe(100);
	Poezd14.Set_plac(200);
	cout << "Поезд14" << endl << endl;
	Poezd14.Print();

	Train arr[SIZE_ARR]
	{
		Sura,
		Poezd14,
	};
	
	string value_point;
	double value_time;
	int value_places,menu;
	
	cout << "1)Список поездов, следующих до заданного пункта назначения" << endl;
	cout << "2)Cписок поездов, следующих до заданного пункта назначения и отправляющихся после заданного часа" << endl;
	cout << "3)Cписок поездов, отправляющихся до заданного пункта назначения и имеющих общие места" << endl;
	cin >> menu;

	if (menu == 1) 
	{
		cout << "Введите название пункта назначения ,для вывода поездов следующих в данный пункт назначения:" << endl;
		cin >> value_point;
		for (int i = 0; i < SIZE_ARR; i++) 
		{
			if (arr[i].Get_point() == value_point)
			{
				cout << i + 1 << ")" << arr[i].Get_num() << endl;
			}
		}
	}
	if (menu == 2)
	{
		cout << "Введите название пункта назначения и время отправления ,для вывода поездов следующих в данный пункт назначения в указанное время:" << endl;
		cin >> value_point;
		cin >> value_time;
		for (int i = 0; i < SIZE_ARR; i++)
		{
			if ((arr[i].Get_point() == value_point) && (arr[i].Get__time() == value_time))
			{
				cout << i + 1 << ")" << arr[i].Get_num() << endl;
			}
		}
	}
	if (menu == 3)
	{
		cout << "Введите название пункта назначения , для вывода поездов с общими местами следующих в данный пункт назначения  : " << endl;
		cin >> value_point;
		for (int i = 0; i < SIZE_ARR; i++)
		{
			if ((arr[i].Get_point() == value_point) && (arr[i].Get_places() > 0))
			{
				cout << i + 1 << ")" << arr[i].Get_num() << endl;
			}
		}
	}
	if ((menu !=1) && (menu !=2) && (menu !=3))
		cout <<"ошибка"<<endl;


    //cout << "Hello World!\n"; 
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
