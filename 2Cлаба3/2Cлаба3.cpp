/****************************************************************************************
*                                                                                       *
*                        ИНФОРМАТИКА И ВЫЧИСЛИТЕЛЬНАЯ ТЕХНИКА                           *
*                                                                                       *
*****************************************************************************************
*    Prodgect type: ConsoleApplication                                                  *
*    Progect name:  2С_Laba2                                                            *
*    File name:     2С_Laba2.сpp                                                        *
*    Language:      Cpp, MSVS 2017                                                      *
*    Programmes:    М3О-107Б-18                                                         *
*                   Гордеев Никита                                                      *
*                   Онгарбаев Бауржан                                                   *
*    Modified by:   28.04.2019                                                          *
*    Created:       28.04.2019                                                          *
*    Comment:       Лабораторная работа №7                                              *
****************************************************************************************/
#include "pch.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

//const char FNAME[] = "Text0.txt";;		//файл не существует
//const char FNAME[] = "Tex1.txt";;			//буква в графе номер рейса
//const char FNAME[] = "Text2.txt";;		//буква в графе вес груза
//const char FNAME[] = "Text3.txt";;		//буква в графе колличество контэйнеров
//const char FNAME[] = "Text4.txt";;		//номер рейса не целое число
//const char FNAME[] = "Text5.txt";;		//колличество контэйнеров не целое число
//const char FNAME[] = "Text6.txt";;		//привэшение NMAX
//const char FNAME[] = "Text7.txt";;		//файл пуст
//const char FNAME[] = "Text8.txt";;		//номер самалёто слишком длинный
//const char FNAME[] = "Text9.txt";;		//номер рейса слишком длинный
//const char FNAME[] = "Text10.txt";;		//вес груза слишком большой
//const char FNAME[] = "Text11txt.txt";;	//колличество контэйнеров слишком большое
//const char FNAME[] = "Text12.txt";;		//последняя строка заполнена не полностью
//const char FNAME[] = "Text13.txt";;		//отрицательное число в графе вес груза
//const char FNAME[] = "Text14txt.txt";;	//отрицательное число в графе номер рейса
//const char FNAME[] = "Text15.txt";;		//отрицательное число в графе количество контейнеров

const char FNAME[] = "Text.txt";;			//файл исходных данных
const int NMAX = 10;

struct Plane
{
	int NReis;			//номер рейса
	string NPlane;		//номер самолёта
	double Mass;		//вес груза
	int  Kont;			//количество контейнеров
};

struct Key
{
	int NReis;			//номер рейса
	int ind;			//индекс сортировки
};

bool InputPlane(Plane *pPlane, int &N, Key *Key);			//ввод структуры из файла
void PrintPlane(Plane *pPlane, int N, Key *Key);			//печать структуры
void SortPlane(int N, Key *Key);							//сортировка структуры
void PrintTabl(Plane *pPlane, int N);						//печать sum и конец таблицы
void Our(int N_oh, const char FNAME[]);						//ошибки

void a() { setlocale(LC_ALL, "C"); }						// подключение английского языка
void r() { setlocale(LC_ALL, "Russian"); }					//подключение русского языка

int main() {
	system("color F0");										//экран белый, буквы черные
	int N;
	Plane APlane[11];
	Key Key[11];
	if (InputPlane(APlane, N, Key))							//ввод из файла
	{
		r();
		cout << "\tДо SortPlane\n";
		PrintPlane(APlane, N, Key);							//печать массива

		SortPlane(N, Key);									//сортировка

		r();
		cout << "\n\tПосле SortPlane\n";
		PrintPlane(APlane, N, Key);							//печать массива
	}
	system("pause");										//пауза
	return 0;
}

void ShapkaTabl() {
	a();
	cout << char(218);
	cout << setfill(char(196)) << setw(4);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(194);
	cout << setfill(char(196)) << setw(15);
	cout << char(191) << endl;
	cout << char(179) << " " << char(252) << " ";
	cout << char(179); r(); cout << "    № рейса   "; a();
	cout << char(179); r(); cout << "бортовой номер"; a();
	cout << char(179); r(); cout << "   вес груза  "; a();
	cout << char(179); r(); cout << "  контейнеры  "; a();
	cout << char(179) << endl;
}

bool InputPlane(Plane * pPlane, int &N, Key *Key)
{
	r();
	bool f;						//флаг верного чтения файла
	int i = 0;					//счетчик числа самолётов
	int j = 0;					//счетчик длины графы номер самолёта
	char a[1];					//вспомогательный массив

	ifstream fin(FNAME);		//открытие входного файла
	ifstream fin2(FNAME);		//открытие входного файла

	if (!fin)					//не удалось открыть файл
	{
		Our(1, FNAME);
		return false;
	}//if	

	i = 0;						//число реально считанных записей
	while (!fin.eof())
	{
		if (i > NMAX - 1) {		//превышение NMAX
			Our(4, FNAME);
			return false;
		}
		fin >> pPlane[i].NReis;
		if ((i == 0) && fin.eof())//файл пуст 
		{
			Our(6, FNAME);
			return false;
		}//if
		if (fin.fail()) {
			Our(2, FNAME);
			return false;
		}
		fin2 >> pPlane[i].NReis;
		fin >> pPlane[i].NPlane;
		if (fin.fail()) {
			Our(2, FNAME);
			return false;
		}
		fin2.read(a, 1);			//уход от пробела
		fin2.read(a, 1);
		if (a[0] != 'Б')
		{
			Our(5, FNAME);
			return false;
		}
		fin2.read(a, 1);
		if (a[0] != '-')
		{
			Our(5, FNAME);
			return false;
		}
		fin2 >> j;
		if ((j < 1000)||(j>9999))
		{
			Our(5, FNAME);
			return false;
		}
		fin >> pPlane[i].Mass;
		fin2 >> pPlane[i].Mass;
		if (fin.fail()) {
			Our(2, FNAME);
			return false;
		}
		if (fin.eof()) {
			Our(8, FNAME);
			return false;
		}
		fin >> pPlane[i].Kont;
		fin2 >> pPlane[i].Kont;
		if (fin.fail()) {
			Our(2, FNAME);
			return false;
		}
		//введённые элементы меньше 0
		if ((pPlane[i].NReis < 0))
		{
			cout << "Отрицательный номер рейса в строке "<< i+1 << " равен "<< pPlane[i].NReis<<"\n";
			Our(3, FNAME);
			return false;
		}
		if ( (pPlane[i].Mass < 0) )
		{
			cout << "Отрицательная масса в строке " << i+1 << " равена " << pPlane[i].Mass << "\n";
			Our(3, FNAME);
			return false;
		}
		if ((pPlane[i].Kont < 0))
		{
			cout << "Отрицательное количество контейнеров в строке " << i+1 << " равено " << pPlane[i].Kont << "\n";
			Our(3, FNAME);
			return false;
		}
		i++;
		f = true;
	}//while

	N = i;
	fin.close();				//закрыть файл
	for (int i = 0; i < N; i++)
	{
		Key[i].NReis = pPlane[i].NReis;
		Key[i].ind = i;
	}
	return f;
}//end InputPlane

int SumPlane(Plane *pPlane, int N) {
	int Sum = 0;						//сумма контейнеров
	for (int i = 0; i < N; i++)
	{
		Sum += pPlane[i].Kont;
	}//for i
	return Sum;
}

void PrintTabl(Plane *pPlane, int N)
{
	a();
	cout << char(195);
	cout << setfill(char(196)) << setw(4);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(193);
	cout << setfill(char(196)) << setw(15);
	cout << char(180) << endl;
	//заполнение
	cout << char(179); r(); cout << " Сумма = "; a(); cout << setfill(char(32)) << setw(25);
	cout << char(32) << " " << setfill(char(32)) << setw(27)
		<< SumPlane(pPlane, N) << " " << char(179) << "\n";
	//конец табл
	cout << char(192);
	cout << setfill(char(196)) << setw(34);
	cout << char(196);
	cout << setfill(char(196)) << setw(30);
	cout << char(217) << endl;
}

//печать массива	
void PrintPlane(Plane * pPlane, int N, Key *Key)
{
	ShapkaTabl();				//шапка
	int i;						//индексная переменная
	//напечатаем и изменим
	for (i = 0; i < N; i++)
	{	//запись
		cout << char(195);
		cout << setfill(char(196)) << setw(4);
		cout << char(197);
		cout << setfill(char(196)) << setw(15);
		cout << char(197);
		cout << setfill(char(196)) << setw(15);
		cout << char(197);
		cout << setfill(char(196)) << setw(15);
		cout << char(197);
		cout << setfill(char(196)) << setw(15);
		cout << char(180) << endl;
		//заполнение табл
		cout << char(179) << " " << setfill(char(32)) << setw(1) << Key[i].ind + 1 << " ";
		cout << char(179) << " " << setfill(char(32)) << setw(12) << pPlane[Key[i].ind].NReis << " ";
		cout << char(179) << " " << setfill(char(32)) << setw(12);
		r(); cout << pPlane[Key[i].ind].NPlane << " "; a();
		cout << char(179) << " " << setfill(char(32)) << setw(12) << pPlane[Key[i].ind].Mass << " ";
		cout << char(179) << " " << setfill(char(32)) << setw(12) << pPlane[Key[i].ind].Kont << " ";
		cout << char(179) << endl;
	}//for i
	PrintTabl(pPlane, N);		//печать таблицы
}//end 

void SortPlane(int N, Key *Key)
{
	int Min;                   	//минимальный элемент
	int jMin;					//индекс минимального элемента
	int iSort;					//граница отсортированной области
	int j;						//индексная переменная
	int Temp;					//обменная переменная

	for (iSort = 0; iSort < N - 1; iSort++)
	{
		//первый элемент из неупорядоченных назначаем минимальным
		Min = Key[iSort].NReis;			//минимум
		jMin = iSort;					//его индекс

		//ищем минимальный элемент в оставшейся части массива
		for (j = iSort + 1; j < N; j++)
		{
			if (Key[j].NReis < Min)		//очередной кандидат на минимальный
			{
				//запоминаем минимальный элемент и его номер
				Min = Key[j].NReis;
				jMin = j;
			}//if

		}//for j

		//нашли минимум в неупорядоченной части массива
		//ставим его на место первого в неупорядоченной части массива
		//меняем элементы местами
		Temp = Key[iSort].NReis;
		Key[iSort].NReis = Key[jMin].NReis;
		Key[jMin].NReis = Temp;
		//сортируем индексный массив
		Temp = Key[iSort].ind;
		Key[iSort].ind = Key[jMin].ind;
		Key[jMin].ind = Temp;

	} //for iSort
}

void Our(int N_oh, const char FNAME[])
{
	switch (N_oh)
	{
	case 1: {cout << "\n\tОшибка!  Файл " << FNAME << " не найден\n"; break; }
	case 2: {cout << "\nОшибка!  Сбой при чтении файла " << FNAME << endl; break; }
	case 3: {cout << "\nОшибка!  Отрицательные значения " << FNAME << "!\n"; break; }
	case 4: {cout << "\nОшибка!  Превышение NMAX " << FNAME << "!\n"; break; }
	case 5: {cout << "\nОшибка!  Файл " << FNAME << " заполнен неправильно\n"; break; }
	case 6: {cout << "\nОшибка!  Файл " << FNAME << " пуст\n"; break; }
	default:
		cout << "Неизвестный код ошибки " << N_oh << endl;
	}
}