// Lab_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <ctime>
#include <set>
#include <string>
#include <cstdlib>

using namespace std;


template <typename T>

class Set
{
private:
	T* m;
	int max_size;
	int size;

public:
	Set(); //Конструктор по умолчанию
	Set(int s); //конструктор спараметрами
	Set(Set<T>& other); //конструктор копирования
	void add(T x); //добавление элемента
	void del(T x); //удаление элемента
	bool check_in(T x);
	Set<T> operator* (const Set<T>& s2);//пересечение множеств
	/*void operator-=(int n) { del(n); };
	void operator-=(const Set<T>&);*/

	bool operator <(Set<T> &s2); //перегрузка оператора сравнения
	void operator-(T x);

	void PrintInfo();

	~Set(); // деструктор

};


template <typename T>
Set<T>::Set()
{
	max_size = 0;
	size = 0;
	m = new T[max_size];
	for (int i = 0; i < max_size; i++)
	{
		m[i] = 0;
	}
}
template <typename T>
Set<T>::Set(int maxim)
{
	m = new T[maxim];
	for (int i = 0; i < maxim; i++)
		m[i] = 0;
	max_size = maxim;
	size = 0;
}
template <typename T>
Set<T> :: Set(Set<T>& other)
{
	max_size = other.max_size;
	m = new T[max_size];
	for (int i = 0; i < max_size; i++)
	{
		m[i] = other.m[i];
	}
}
template <typename T>
Set<T>::~Set()
{
	delete[] m;
}

template <typename T>
void Set<T> ::operator-(T n)
{
	if (size > 0)
	{
		int* t, pos;
		for (pos = 0; pos < size && m[pos] < n; pos++) {}
		if (m[pos] == n)
		{
			t = new T[--size];
			for (int i = 0; i < size + 1; i++)
				if (i != pos) t[i < pos ? i : i - 1] = m[i];
			delete[]m;
			m = t;
		}
	}
}

template <typename T>
void Set<T> ::add(T n)
{
	int* t, pos;
	for (pos = 0; pos < size && m[pos] < n; pos++) {}
	if (m[pos] != n)
	{
		t = new T[++size];
		for (int i = 0; i < size - 1; i++)
			t[i < pos ? i : i + 1] = m[i];
		t[pos] = n;
		delete[] m;
		m = t;
	}
}
template<typename T>
void Set<T> ::del(T n)
{
	if (size > 0)
	{
		int* t, pos;
		for (pos = 0; pos < size && m[pos] < n; pos++) {}
		if (m[pos] == n)
		{
			t = new T[--size];
			for (int i = 0; i < size + 1; i++)
				if (i != pos) t[i < pos ? i : i - 1] = m[i];
			delete[]m;
			m = t;
		}
	}
}


template <class T>
bool Set <T>::check_in(T x)
{
	for (int i = 0; i < size; i++)
		if (m[i] == x)
			return true;
	return false;
}

template <typename T>
 void Set<T>::PrintInfo()
{
	 for (int i = 0; i < size; i++)
	 {
		 cout << m[i] << "\t";
	 }
	 cout << endl;
}
 template<typename T>
 Set<T> Set<T> :: operator*(const Set<T>& x)
 {
	 Set<T> t(*this), t2(*this);
	 t -= x;
	 for (int i = 0; i < t.size; ++i)
		 t2.add(t.m[i]);
	 return t2;
 }
 template<typename T>
 bool Set<T> :: operator<(Set<T>& s2)
 {
	 if (this->size < s2.size)
		 return true;
	 else return false;
 }

 //template<typename T>
 //void Set<T>::operator-=(const Set<T>& x)
 //{
	// for (int i = 0; i < x.size; i++)
	//	 return del(x.m[i]);
 //}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

	bool f;

	Set<int> arr;
	arr.add(3);
	arr.add(55);
	arr.add(7);
	arr.add(1);
	arr.PrintInfo();

	arr - 7;
	arr.PrintInfo();

	

	Set<int> arr2;
	arr2.add(14);
	arr2.add(3);
	arr2.add(55);

	arr2.PrintInfo();

	/*Set<int> kk;
	kk = arr * arr2;
	kk.PrintInfo();*/

	if (arr < arr2)
	{
		cout << "true" << endl;
	}
	else cout << "false" << endl;

	
	

     
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
