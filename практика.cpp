/*************************************************************************************************
*                                                                                                *
*                          ИНФОРМАТИКА И ВЫЧИСЛИТЕЛЬНАЯ ТЕХНИКА                                  *
*                                                                                                *
**************************************************************************************************
*    Prodgect type: ConsoleApplication                                                           *
*    Progect name:  Laba1                                                                        *
*    File name:     Laba1.sln                                                                    *
*    Language:      Cpp, MSVS 2017                                                               *
*    Programmes:    М3О-107Б-18                                                                  *
*                   Гордеев Никита                                                               *
*    Modified by:   01.03.2019                                                                   *
*    Created:       10.04.2019                                                                   *
*    Comment:       Практика                                                                     *
*************************************************************************************************/
#include "pch.h"
#include <conio.h>
#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

double kopenb1(double a, double b, bool r, int &N, int &t);
double kopenb2(double a, bool r, int &N, int &t);
void tabl_3(double x, int N, int t);
void tabl_4(int N, int t);
void tabl_5();
void A() { setlocale(LC_ALL, "C"); }						// подключение английского языка
void r() { setlocale(LC_ALL, "Russian"); }					//подключение русского языка

int main() {
	//setlocale(LC_ALL, "Russian");
	int N = 0;					// Номер итерации
	int t = 0;					// Номер итерации

	double x = 0;					// Номер итерации
	// Инициализация переменных
	int a = -9;					// Граница 1
	int b = 1;					// Граница 2
	int c = 2;					// Граница 2
	int d = 4;					// Граница 4
	r();
	//cout << "\n\n\tПервое уровнение по методу половинного деления\n\n";
	cout << "\n\n\tПервое уравнение методом половинного деления\n\n";
	//cout << "Корень на участке (" << a << " ; " << b << ") равен ";
	cout << "Корень на участке (" << a << " ; " << b << ") равен ";
	x = kopenb1(a, b, 0, N, t);
	cout << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << (x - 2)*(x - 2)*pow(2, x) << "\t";
	cout << "T = "<< t << "\n\n";

	cout << "Корень на участке (" << b << " ; " << c << ") равен ";
	x = kopenb1(b, c, 0, N, t);
	cout << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << (x - 2)*(x - 2)*pow(2, x) << "\t";
	cout << "T = " << t << "\n\n";

	cout << "Корень на участке (" << c << " ; " << d << ") равен ";
	x = kopenb1(c, d, 0, N, t);
	cout << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << (x - 2)*(x - 2)*pow(2, x) << "\t";
	cout << "T = " << t << "\n\n";

	//cout << "\n\n\tВторое уровнение по методу половинного деления\n\n";
	cout << "\n\n\tВторое уровнение методом половинного деления\n\n";
	cout << "Корень на учатске (" << a << " ; " << b << ") равен ";
	x = kopenb1(a, b, 1, N, t);
	//cout << x << " и получен за " << N << " попыток\n";
	cout << x << "  и получен за " << N << " итераций\n";
	cout << "f(x0)= " << 4 - pow(2.718281828459045, x) - 2 * x << "\t";
	cout << "T = " << t << "\n\n";

	//cout << "\n\n\tПервое уровнение по методу Ньютона \n\n";
	cout << "\n\n\tПервое уровнение методом Ньютона \n\n";
	x = kopenb2(a, 1, N, t);
	//cout << "Корень в близи значения (" << a << ") равен " << x << " и получен за " << N << " попыток\n";
	cout << "Корень в близи числа (" << a << ") равен " << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << (x - 2)*(x - 2)*pow(2, x) << "\t";
	cout << "T = " << t << "\n\n";

	x = kopenb2(b, 1, N, t);
	cout << "Корень в близи числа (" << b << ") равен " << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << (x - 2)*(x - 2)*pow(2, x) << "\t";
	cout << "T = " << t << "\n\n";

	x = kopenb2(d, 1, N, t);
	cout << "Корень в близи числа (" << d << ") равен " << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << (x - 2)*(x - 2)*pow(2, x) << "\t";
	cout << "T = " << t << "\n\n";

	//cout << "\n\n\tВторое уровнение по методу Ньютона \n\n";
	cout << "\n\n\tВторое уравнение методом ньютона \n\n";
	x = kopenb2(c, 0, N, t);
	cout << "Корень в близи числа (" << c << ") равен " << x << " и получен за " << N << " итераций\n";
	cout << "f(x0)= " << 4 - pow(2.718281828459045, x) - 2 * x << "\t";
	cout << "T = " << t << "\n\n\n\n";

	cout << "\t\t   Метод половинного деления" << "\t\t   Метод ньютона\n";
	A(); cout << char(218);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(191) << endl;
	cout << char(179) << "      x       ";
	cout << char(179) << "      n       ";
	cout << char(179) << "      t       ";
	cout << char(179) << "      n       ";
	cout << char(179) << "      t       ";
	cout << char(179) << endl;
	cout << char(195);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(180) << endl;

	tabl_3(kopenb1(a, b, 0, N, t), N, t);
	kopenb2(a, 1, N, t);
	tabl_4(N, t);
	tabl_5();

	tabl_3(kopenb1(b, c, 0, N, t), N, t);
	kopenb2(b, 1, N, t);
	tabl_4(N, t);
	tabl_5();

	tabl_3(kopenb1(c, d, 0, N, t), N, t);
	kopenb2(d, 1, N, t);
	tabl_4(N, t);
	tabl_5();

	tabl_3(kopenb1(a, b, 1, N, t), N, t);
	kopenb2(c, 0, N, t);
	tabl_4(N, t);
	A(); cout << char(192);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(217) << endl;

	_getch();
	return 0;
}

void tabl_3(double x, int N, int t) {
	A(); cout << char(179) << " " << setfill(char(32)) << setw(12) << x << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << N << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << t << " ";
	cout << char(179); r();
}
void tabl_4(int N, int t) {
	A(); cout <<  " " << setfill(char(32)) << setw(12) << N << " ";
	cout << char(179) << " " << setfill(char(32)) << setw(12) << t << " ";
	cout << char(179) << endl; r();
}
void tabl_5() {
	A(); cout << char(195);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(197);
	cout << setfill(char(196)) << setw(15);
	cout << char(180) << endl; r();
}
/*************************************************************************************************
										 ПЕРВЫЙ СПОСОБ
*************************************************************************************************/
double kopenb1(double a, double b, bool r, int &N, int &t) {
	int start_time = clock();	// начальное время
	double Eps = 0.0001;		// Точность
	double f;					// f(x)
	double fa;					// f(a)
	double fb;					// f(b)
	double l = 0;				// длинна
	N = 0;						// Номер итерации
	double m;					// Вспомогательная переменная
	if (r == 0)
	{
		fa = (a - 2)*(a - 2)*pow(2, a) - 1;
		fb = (b - 2)*(b - 2)*pow(2, b) - 1;
	}
	else
	{
		fa = 4 - pow(2.718281828459045, a) - 2 * a;
		fb = 4 - pow(2.718281828459045, b) - 2 * b;
	}
	//если вункция на участке убывает меняем местами концы отрезка
	if (fa > fb) { m = a; a = b; b = m; }

	double x = a;				// Переменная
	if (r == 0)
		f = (x - 2)*(x - 2)*pow(2, x) - 1;
	else
		f = 4 - pow(2.718281828459045, x) - 2 * x;

	while (abs(f) > Eps)
	{
		if (f < 0) a = a + l;
		else b = b - l;
		l = (b - a) / 2;
		x = a + l;
		if (r == 0)
			f = (x - 2)*(x - 2)*pow(2, x) - 1;
		else

			f = 4 - pow(2.718281828459045, x) - 2 * x;
		N++;
		//tabl(x, f, N);
	}
	int end_time = clock(); // конечное время
	t = end_time - start_time;
	return x;
}
/*************************************************************************************************
											ВТОРОЙ СПОСОБ
*************************************************************************************************/
double kopenb2(double a, bool r, int &N, int &t) {
	int start_time = clock();	// начальное время
	double Eps = 0.0001;		// Точность
	double f;					// f(x)
	double x1;					// f
	double f2;					// f'(x)
	N = 0;						// Номер итерации
	double x = a;				// Переменная
	if (r == 0)
	{
		f = 4 - pow(2.718281828459045, x) - 2 * x;
		f2 = -pow(2.718281828459045, x) - 2;
	}
	else
	{
		f = (x - 2)*(x - 2)*pow(2, x) - 1;
		f2 = 2 * (x - 2)*pow(2, x) + pow(2, x)*log(2)*(x - 2)*(x - 2);
	}
	x1 = x - f / f2;
	while (abs(x1-x) > Eps)
	{
		x = x1;
		if (r == 0)
		{
			f = 4 - pow(2.718281828459045, x) - 2 * x;
			f2 = -pow(2.718281828459045, x) - 2;
		}
		else
		{
			f = (x - 2)*(x - 2)*pow(2, x) - 1;
			f2 = 2 * (x - 2)*pow(2, x) + pow(2, x)*log(2)*(x - 2)*(x - 2);
		}
		x1 = x - f / f2;
		N++;
	}
	int end_time = clock(); // конечное время
	t = end_time - start_time;
	return x;
}