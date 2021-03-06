#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void menu()
{
	cout << "	Меню" << endl << "(Для выполнения введите номер задания)" << endl;
	cout << "1)Ввод или вывод матриц" << endl;
	cout << "2)Работа с фалами" << endl;
	cout << "3)Перемножение матриц" << endl;
	cout << "4)Возведение 1-й матрицы в степень" << endl;
	cout << "5)Изменение размерности матриц" << endl;
	cout << "6)1- дополнительно задание" << endl;
	cout << "7)2- дополнительно задание" << endl;
	cout << "8)Заполнение матриц случаными числами(для ленивых)" << endl;
	cout << "9)Выход" << endl;
}
void matrix_selection()
{
	cout << "Выберите матрицу" << endl;
	cout << "1. a" << endl;
	cout << "2. b" << endl;
	cout << "3. Назад" << endl;
}
void output(int **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
void output(float **a, int n)
{
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}
int** input(int n)
{
	int i, j;

	int **a = new int*[n];
	for (int count = 0; count < n; count++)
		a[count] = new int[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}

	return a;
	for (int count = 0; count < n; count++)
		delete[] a[count];
}
void record(string adress, int **a, int n)
{
	ofstream file;
	int i, j;

	file.open(adress);
	if (!file.is_open())
		cout << "Ошибка" << endl;
	else
	{
		file << n << endl;
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				file << a[i][j] << " ";
			}
			file << endl;
		}
		file.close();
	}
}
int** reading(string adress, int n)
{
	int i, j;
	ifstream file;
	char q;
	int **a = new int*[n];
	for (int count = 0; count < n; count++)
		a[count] = new int[n];

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			file.get(q);
			a[i][j] = int(q);
		}
	}
	file.close();
	return a;
	for (int count = 0; count < n; count++)
		delete[] a[count];
}
int** multiplication(int **a, int**b, int n)
{
	int **c = new int*[n];
	for (int count = 0; count < n; count++)
		c[count] = new int[n];

	int i, j, w;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			c[i][j] = 0;
			for (w = 0; w < n; w++)
			{
				c[i][j] += a[i][w] * b[w][j];
			}
		}
	}
	return c;
	for (int count = 0; count < n; count++)
		delete[] c[count];
}
int** involution(int **a, int  n, int power)
{
	int i, j;

	int **c = new int*[n];
	for (int count = 0; count < n; count++)
		c[count] = new int[n];

	int **c_2 = new int*[n];
	for (int count = 0; count < n; count++)
		c_2[count] = new int[n];

	switch (power)
	{
	case 1:
		c = a;
		break;

	case 2:
		c = multiplication(a, a, n);
		break;

	default:
		c = multiplication(a, a, n);
		for (int q = 2; q < power; q++)
		{
			for (i = 0; i < n; i++)
			{
				for (j = 0; j < n; j++)
				{
					c_2[i][j] = c[i][j];
				}
			}
			c = multiplication(c_2, a, n);
		}
		break;
	}
	for (int count = 0; count < n; count++)
		delete[] c_2[count];

	return c;

	for (int count = 0; count < n; count++)
		delete[] c[count];
}
int** increase_size(int **a, int n)
{
	int **p = new int*[n];
	for (int count = 0; count < n; count++)
		p[count] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = (i < n - 1) && (j < n - 1) ? a[i][j] : 0;
		}
	}
	for (int count = 0; count < n - 1; count++)
		delete[] a[count];

	return p;
}
int** reduce_size(int **a, int n)
{
	int **p = new int*[n];
	for (int count = 0; count < n; count++)
		p[count] = new int[n];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			p[i][j] = a[i][j];
		}
	}
	for (int count = 0; count < n + 1; count++)
		delete[] a[count];

	return p;
}
float** additional_task(int **a, int** b, int n)
{
	int max_a, max_b; // максимум стобца
	int i, j;
	float **d = new float*[n];
	for (int count = 0; count < n; count++)
		d[count] = new float[n];

	for (j = 0; j < n; j++)
	{
		max_a = a[0][j];
		max_b = b[0][j];
		for (i = 0; i < n; i++)
		{
			if (a[i][j] > max_a)
				max_a = a[i][j];
			if (b[i][j] > max_b)
				max_b = b[i][j];
		}
		if ((max_a*max_b) != 0)
		{
			for (i = 0; i < n; i++)
			{
				d[i][j] = (float)(a[i][j] * b[i][j]) / (float)(max_a*max_b);
			}
		}
		else
		{
			for (i = 0; i < n; i++)
			{
				d[i][j] = (float)(a[i][j] * b[i][j]);
			}
		}
	}

	return d;
	for (int count = 0; count < n; count++)
		delete[] d[count];

}
int** comparison(int **a, int**b, int n)
{
	int **c = new int*[n];
	for (int count = 0; count < n; count++)
		c[count] = new int[n];

	int i, j;
	char flag = 0;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (a[j][i] != b[j][i])
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0)
		{
			for (j = 0; j < n; j++)
			{
				c[j][i] = a[j][i];
			}
		}
		else
		{
			for (j = 0; j < n; j++)
			{
				c[j][i] = 0;
			}
		}
		flag = 0;
	}
	return c;
	for (int count = 0; count < n; count++)
		delete[] c[count];
}
int** random_matrix(int n)
{
	int **a = new int*[n];
	for (int count = 0; count < n; count++)
		a[count] = new int[n];
	int i, j;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			a[i][j] = (rand() % 50);

		}
	}
	return a;
	for (int count = 0; count < n; count++)
		delete[] a[count];
}
int main()
{
	setlocale(0, "rus");
	int lvl_1, lvl_2, lvl_3, i, j, power;
	int n_a, n_b;// размерность матриц
	string adress;
	ifstream file;// файловые переменные
	char flag_a = 0, flag_b = 0, flag_c = 0, flag_d = 0; // flag=0 - матрица отсутствует flag=1 - матрица введена 
	char n;
	int** a = 0;
	int** b = 0;
	int** c = 0;
	float** d = 0;// динамические матрицы
	do {
		menu();
		cin >> lvl_1;
		if (lvl_1 == 1)
		{
			do {
				cout << "Что вам нужно?" << endl;
				cout << "1. Ввести матрицу" << endl;
				cout << "2. Вывести матрицу" << endl;
				cout << "3. Назад" << endl;
				cin >> lvl_2;

				switch (lvl_2) {
				case 1:
					do {
						matrix_selection();
						cin >> lvl_3;
						switch (lvl_3) {
						case 1:
							cout << "Введите размер квадратоной матрицы" << endl;
							cin >> n_a;
							a = input(n_a);
							flag_a = 1;
							break;
						case 2:
							cout << "Введите размер квадратоной матрицы" << endl;
							cin >> n_b;
							b = input(n_b);
							flag_b = 1;
							break;
						default:
							lvl_3 = 3;
							break;
						}
					} while (lvl_3 != 3);
					break;
				case 2:
					matrix_selection();
					cin >> lvl_3;
					switch (lvl_3) {
					case 1:
						if (flag_a == 1)
							output(a, n_a);
						else
							cout << "К сожалению, вам нечего выводить" << endl;
						break;
					case 2:
						if (flag_b == 1)
							output(b, n_b);
						else
							cout << "К сожалению, вам нечего выводить" << endl;
						break;
					}
					break;
				}
			} while (lvl_2 != 3);
		}
		if (lvl_1 == 2)
		{
			do {
				cout << "Что вам нужно?" << endl;
				cout << "1. Сохранить матрицу в файл" << endl;
				cout << "2. Взять данные из файла" << endl;
				cout << "3. Назад" << endl;
				cin >> lvl_2;

				switch (lvl_2) {
				case 1:
					do {
						matrix_selection();
						if (flag_c == 1)
							cout << "4. c" << endl;
						cin >> lvl_3;
						switch (lvl_3) {
						case 1:
							if (flag_a == 1)
							{
								cout << "Введите адрес файла или название" << endl;
								cin >> adress;
								record(adress, a, n_a);
							}
							else
							{
								cout << "Матрица отсутствует" << endl;
							}
							break;
						case 2:
							if (flag_b == 1)
							{
								cout << "Введите адрес файла или название" << endl;
								cin >> adress;
								record(adress, b, n_b);
							}
							else
							{
								cout << "Матрица отсутствует" << endl;
							}
							break;
						case 4:
							if (flag_c == 1)
							{
								cout << "Введите адрес файла или название" << endl;
								cin >> adress;
								record(adress, c, n_a);
							}
							else
							{
								cout << "Матрица отсутствует" << endl;
							}
							break;
						default:
							lvl_3 = 3;
							break;
						}
					} while (lvl_3 != 3);
					break;
				case 2:
					do {
						matrix_selection();
						cin >> lvl_3;
						switch (lvl_3) {
						case 1:
							cout << "Введите адрес файла или название" << endl;
							cin >> adress;
							file.open(adress);
							file.get(n);
							n_a = (int)n - 48;
							file.close();
							a = reading(adress, n_a);

							break;
						case 2:
							/*cout << "Введите адрес файла или название" << endl;
							cin >> adress;
							file_2.open(adress);
							file_2.get(n_2);
							int(n_2);
							n_b= n_2;
							int **e = new int*[n_2];
							for (int count = 0; count < n_2; count++)
								e[count] = new int[n_2];

							for (i = 0; i < n_2; i++)
							{
								for (j = 0; j < n_2; j++)
								{
									file_2.get(q_2);
									int(q_2);
									e[i][j] = q_2;
									char(q_2);
								}
							}
							file_2.close();
							b = e;

							for (int count = 0; count < n_2; count++)
								delete[] e[count];*/
							break;
						}
					} while (lvl_3 != 3);
					break;
				}


			} while (lvl_2 != 3);
		}
		if (lvl_1 == 3)
		{
			if (n_a == n_b)
			{
				cout << "Какую на какую" << endl;
				matrix_selection();
				cin >> lvl_2;

				switch (lvl_2) {
				case 1:
					c = multiplication(a, b, n_a);
					output(c, n_a);
					break;
				case 2:
					c = multiplication(b, a, n_a);
					output(c, n_a);
					break;
				}
				flag_c = 1;
			}
			else
			{
				cout << "Размеры не совпадают" << endl;
			}

		}
		if (lvl_1 == 4)
		{
			cout << "В какую степень хотите вовести?" << endl;
			cin >> power;
			c = involution(a, n_a, power);
			output(c, n_a);
			flag_c = 1;
		}
		if (lvl_1 == 5)
		{
			do {
				cout << "Как изменить размерность ?" << endl;
				cout << "1. Увеличить" << endl;
				cout << "2. Уменьшить" << endl;
				cout << "3. Назад" << endl;
				cin >> lvl_2;
				switch (lvl_2)
				{
				case 1:
					matrix_selection();
					cin >> lvl_3;
					switch (lvl_3)
					{
					case 1:
						n_a++;
						a = increase_size(a, n_a);
						output(a, n_a);
						break;
					case 2:
						n_b++;
						b = increase_size(b, n_b);
						output(b, n_b);
						break;
					}
					break;
				case 2:
					matrix_selection();
					cin >> lvl_3;
					switch (lvl_3)
					{
					case 1:
						n_a--;
						a = reduce_size(a, n_a);
						output(a, n_a);
						break;
					case 2:
						n_b--;
						b = reduce_size(b, n_b);
						output(b, n_b);
						break;
					}
					break;
				default:
					lvl_2 = 3;
					break;
				}
			} while (lvl_2 != 3);
		}
		if (lvl_1 == 6)
		{
			if (n_a == n_b)
			{
				d = additional_task(a, b, n_a);
				output(d, n_a);
				flag_d = 1;
			}
			else
			{
				cout << "Размеры не совпадают" << endl;
			}
		}
		if (lvl_1 == 7)
		{
			if (n_a == n_b)
			{
				c = comparison(a, b, n_a);
				output(c, n_a);
				flag_c = 1;
			}
			else
			{
				cout << "Размеры не совпадают" << endl;
			}
		}
		if (lvl_1 == 8)
		{
			cout << "Введите размер квадратоной матрицы" << endl;
			cin >> n_a;
			n_b = n_a;
			a = random_matrix(n_a);
			b = random_matrix(n_a);
			flag_a = 1;
			flag_b = 1;
			output(a, n_a);
			cout << endl;
			output(b, n_a);
		}
	} while (lvl_1 != 9);

	if (flag_a == 1)
		for (int count = 0; count < n; count++)
			delete[] a[count];

	if (flag_b == 1)
		for (int count = 0; count < n; count++)
			delete[] b[count];

	if (flag_c == 1)
		for (int count = 0; count < n; count++)
			delete[] c[count];

	if (flag_d == 1)
		for (int count = 0; count < n; count++)
			delete[] b[count];//освобождение памяти 

	return 0;

}
