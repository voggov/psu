#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <ctime>
#include <conio.h>
#include <windows.h>
#include <chrono>

using namespace std;



void shell(int* items, int count)
{

	int i, j, gap, k;
	int x, a[5];

	a[0] = 9; a[1] = 5; a[2] = 3; a[3] = 2; a[4] = 1;

	for (k = 0; k < 5; k++) {
		gap = a[k];
		for (i = gap; i < count; ++i) {
			x = items[i];
			for (j = i - gap; (x < items[j]) && (j >= 0); j = j - gap)
				items[j + gap] = items[j];
			items[j + gap] = x;
		}
	}
}
class Timer
{
private:
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;

	std::chrono::time_point<clock_t> m_beg;

public:
	Timer() : m_beg(clock_t::now())
	{
	}

	void reset()
	{
		m_beg = clock_t::now();
	}

	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};


void qs(int* items, int left, int right) //вызов функции: qs(items, 0, count-1);
{
	int i, j;
	int x, y;



	i = left; j = right;

	/* выбор компаранда */
	x = items[(left + right) / 2];

	do {
		while ((items[i] < x) && (i < right)) i++;
		while ((x < items[j]) && (j > left)) j--;

		if (i <= j) {
			y = items[i];
			items[i] = items[j];
			items[j] = y;
			i++; j--;
		}
	} while (i <= j);

	if (left < j) qs(items, left, j);
	if (i < right) qs(items, i, right);
}


int main(void)
{

	setlocale(LC_ALL, "Russian");
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);

	time_t start, end; // объявляем переменные для определения времени выполнения
	FILE* TABLE;
	int i = 1, j = 0, r;
	int n;
	//int a[400][400], b[400][400], c[400][400], elem_c;
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел

	cout << "Введите размер массива : "; cin >> n; cout << endl;
	int* A = new int[n];
	int m = n / 2;
	int raz = 1 + rand() % 10;
	A[0] = rand() % 1001;
	while (i < n)
	{

		A[i] = rand() % 1001;
		cout << A[i] << "\t" << endl;
		i++;
	}
	/*j = n / 2;
	while (j < n )
	{

		A[j] = A[j - 1] - rand() % 101;
		cout << A[j] << "\t" << endl;
		j++;
	}*/

	time(&start);
	Timer t;
	shell(A, n);
	double tm1 = t.elapsed();
	time(&end);
	TABLE = fopen("TABLE.txt", "a");
	fprintf(TABLE, "\nубывающ \t :%f\t ||", tm1);
	fclose(TABLE);
	int search_t = difftime(end, start);
	//cout << "Время на сортировку Шелла: " << search_t<< endl;
	printf("Время на сортировку %f\n", tm1);
	cout << "Сортировка Шелла :";

	for (i = 0; i < n; i++) {
		cout << A[i] << "\t";
	}
	cout << endl;
	Timer t1;
	qs(A, 0, n - 1);
	double tm2 = t1.elapsed();
	TABLE = fopen("TABLE.txt", "a");
	fprintf(TABLE, "\t :%f\n", tm2);
	fclose(TABLE);
	//cout << "Время на Быструю сортировку: " <<t1.elapsed() << endl;
	printf("Время на сортировку быструю %f\n", tm2);
	cout << "Быстрая сортировка : ";

	for (i = 0; i < n; i++)
		cout << A[i] << "\t";
	cout << endl;







	/* while (i < 400)
	{
		while (j < 400)
		{
			a[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	srand(time(NULL)); // инициализируем параметры генератора случайных чисел
	i = 0; j = 0;
	while (i < 400)
	{
		while (j < 400)
		{
			b[i][j] = rand() % 100 + 1; // заполняем массив случайными числами
			j++;
		}
		i++;
	}
	unsigned int start_time = clock();
	for (i = 0; i < 400; i++)
	{
		for (j = 0; j < 400; j++)
		{
			elem_c = 0;
			for (r = 0; r < 400; r++)
			{
				elem_c = elem_c + a[i][r] * b[r][j];
				c[i][j] = elem_c;
			}
		}
	}
	unsigned int end_time = clock();
	unsigned int search_time = end_time - start_time;
	unsigned int time1 = clock();
	cout << "Время на умножение матрицы 400 х 400 =" << search_time << "секунд" << std::endl;
	cout << "Время работы всей программы =" <<time1 << std::endl;
	cout << a;*/



	return(0);
}
