// Ur1_mod7_Prakt_rab_1518841107.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

#define sz 9
#define sz7 5

void sort_ub(int * arr1);
void sort_vz(int * arr);
void F6(int * mass, int dl_mas, int &valp, int &valm, int &val0);
void countEven(int * arr, int dl, int &cnt);
void F9_max(double * mass, int dl, int *index);
void myStrLen(char * arr, int * dlina);

int main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int n = 0;
	printf("\t Urok_1__Modul__7__Prakticeskaa_rabota_1518841107 \n");
	printf_s("\n");
	do {
		if (n == 1)
		{
			/*	1. Напишите программу, чтобы вычислить сумму всех
			элементов в массиве с помощью указателей.
			*/
			int ms1[13] = { 0 };
			int s = 0;
			for (int i = 0; i < 13; i++)
			{
				*(ms1 + i) = 1 + rand() % 10;
				printf("\t%d", *(ms1 + i));
				s += *(ms1 + i);
			}
			printf("\nSumma vsex elementov:  %d", s);
			printf_s("\t\n");
		}

		else if (n == 2)
		{
			/* 2.	Напишите программу, чтобы напечатать
			элементы массива в обратном порядке  	*/
			int ms2[8] = { 0 };
			int * pt_end = &ms2[7];
			for (int i = 0; i < 8; i++)
			{
				*(ms2 + i) = 1 + rand() % 10;
				printf("\t%d", *(ms2 + i));
			}
			printf_s("\n\t print massiva v obratnom poriadke\n");
			for (int i = 0; i < 8; i++)
			{
				printf("\t%d", *(pt_end - i));
			}
			printf_s("\t   \n");
		}

		else if (n == 3)
		{
			/*	3.	Напишите программу, которая сортирует список целых чисел в порядке возрастания.
			Однако, если в командной строке присутствует отрицательное число, ваша программа
			должна сортировать список в порядке убывания.
			(Вы можете использовать любую процедуру сортировки, которую вы хотите)  */
			int ms3[sz] = { 0 };
			int fl_sort = 1;
			for (int i = 0; i < sz; i++)
				*(ms3 + i) = 1 + rand() % 11;
			int k = rand() % sz;
			*(ms3 + k) = 2 - rand() % 5;
			printf_s("\t isxodnii massiv \n");
			for (int i = 0; i < sz; i++)
			{
				printf("\t%d", *(ms3 + i));
				if (*(ms3 + i) < 0)
					fl_sort = 0;
			}
			printf_s("\t   \n");
			if (fl_sort == 1)
			{
				printf("\t sortirovka po vozrastiu\n");
				sort_vz(ms3);
			}
			else 
			{
				printf("\t sortirovka po ubyvaniu\n");
				sort_ub(ms3);
			}
			printf_s("\t otsortirovannii massiv \n");
			for (int i = 0; i < sz; i++)
				printf("\t%d", *(ms3 + i));
			printf_s("\t   \n");
		}
		
		else if (n == 4)
		{
			/* 4.	Пользуясь двумя указателями на массив целых чисел,	скопировать один массив в другой.
			Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.*/
			int ms41[sz] = { 0 };
			int ms42[sz] = { 0 };
			printf_s("\t isxodnii massiv  \n");
			for (int i = 0; i < sz; i++)
			{
				*(ms41 + i) = 1 + rand() % 15;
				printf("\t%d", *(ms41 + i));
			}
			printf_s("\t   \n");
			printf_s("\t drugoi skopirovannii massiv  \n");
			for (int i = 0; i < sz; i++)
			{
				*(ms42 + i) = *(ms41 + i);
				printf("\t%d", *(ms42 + i));
			}
			printf_s("\t\n");
		}

		else if (n == 5)
		{
			/*	5. Пользуясь указателем на массив целых чисел,	изменить порядок следования элементов массива на противоположный.
			Использовать в программе арифметику указателей для продвижения по массиву, а также оператор разыменования.*/
			int ms5[sz] = { 0 };
			int seredina = sz / 2;
			int obmen = 0;
			int * pt_end = &ms5[sz - 1];
			printf_s("\t isxodnii massiv   \n");
			for (int i = 0; i < sz; i++)
			{
				*(ms5 + i) = 1 + rand() % 20;
				printf("\t%d", *(ms5 + i));
			}
			printf_s("\t   \n");
			for (int i = 0; i <= seredina; i++)   // меняются местами равноудаленные от середины элементы, 
			{                                     // а середина остается на месте 
				obmen = *(ms5 + i);
				*(ms5 + i) = *(pt_end - i);
				*(pt_end - i) = obmen;
			}
			printf_s("\t\n");
			printf_s("\t obratnii poriadok sledovania v massive  \n");
			for (int i = 0; i < sz; i++)
				printf("\t%d", *(ms5 + i));
			printf_s("\t\n");
		}
		else if (n == 6)
		{
			/*  6.	Написать функцию, которая получает указатель на массив и его размер,
			и возвращает количество отрицательных, положительных и нулевых элементов массива. 	*/
			int ms6[sz] = { 0 };
			printf_s("\t isxodnii massiv   \n");
			for (int i = 0; i < sz; i++)
			{
				*(ms6 + i) = 15 - rand() % 20;
				printf("\t%d", *(ms6 + i));
			}
			printf_s("\t   \n");
			int cntp = 0;
			int cntm = 0;
			int cnt0 = 0;
			F6(ms6, sz, cntp, cntm, cnt0);
			printf("elementov v massive: pol= %d, otr= %d, nul= %d", cntp, cntm, cnt0);
			printf_s("\t   \n");
		}

		else if (n == 7)
		{
			/* 7.	Даны два массива: А[M] и B[N] (M и  N вводятся с клавиатуры).
			Необходимо создать третий массив минимально возможного размера,
			в котором нужно собрать общие элементы двух массивов без повторений. */
			int ms71[sz] = { 0 };
			int ms72[sz7] = { 0 };
			int ms73[sz] = { 0 };
			int cnt = 0;
			int *pt_ms73=&ms73[0];
			printf("Massiv1: \n");
			for (int i = 0; i < sz; i++)
			{
			*(ms71 + i) = 1 + rand() % 10;
			printf("\t%d", *(ms71 + i));
			}
			printf_s("\t   \n");
			printf("Massiv2: \n");
			for (int i = 0; i < sz7; i++)
			{
				*(ms72 + i) = 1 + rand() % 10;
				printf("\t%d", *(ms72 + i));
			}
			printf_s("\t   \n");
			ms73[0] = ms71[0];
			for (int i = 0; i < sz; i++)
			{
				for (int j=0;j<sz;j++)
				{
					if (*(ms73 + i) != *(ms71 + j))
					{
						cnt++;
						*(pt_ms73 + cnt) = *(ms71 + j);
					}	
					
				}
			}
			for (int i = 0; i < sz; i++)
				printf("\t%d", *(ms73 + i));
			printf_s("\t   \n");
		}
		else if (n == 8)
		{
			/* 8. Напишите функцию countEven (int *, int), которая
			получает целочисленный массив и его размер, и возвращает число четных чисел в массиве. */
			int cntev = 0;
			int ms8[sz] = { 0 };
			printf_s("\t isxodnii massiv   \n");
			for (int i = 0; i < sz; i++)
			{
				*(ms8 + i) = 15 + rand() % 20;
				printf("\t%d", *(ms8 + i));
			}
			printf_s("\t   \n");
			countEven(ms8, sz, cntev);
			printf("kol-vo even = %d", cntev);
			printf_s("\t   \n");
		}
		else if (n == 9)
		{
			/* 9.	Напишите функцию, которая возвращает указатель на максимальное значение массива double.
			Если массив пуст, верните NULL. */
			int ind = 0;
			int *pt_ind = &ind;
			double ms9[sz] = { 0 };
			printf_s("\t isxodnii massiv   \n");
			for (int i = 0; i < sz; i++)
			{
				*(ms9 + i) = 15.22 + i * 0.56 + rand() % 20;
				printf("\t%7.2f", *(ms9 + i));
			}
			printf_s("\t   \n");
			F9_max(ms9, sz, pt_ind);
			if (ind == 0) pt_ind = NULL;
			printf("max index: %d, max pointer: %p", ind, pt_ind);
			printf_s("\t   \n");
		}
		else if (n == 10)
		{
			/* 10.	Напишите функцию myStrLen (char *), которая возвращает длину параметра cstring.
			Запишите функцию, не используя функцию C. */
			char ms10[] = "stroka dlia podscheta dlini";
			int cnt = 0;
			char * p_ms10 = &ms10[0];
			printf_s("\t isxodnii massiv ms10 = %s   \n", ms10);
			myStrLen(p_ms10, &cnt);
			printf_s("\t  dlina podschitannaia:  %d \n", cnt);
			printf_s("\t   \n");
		}

		printf("Vvod nomera zadania, 0-exit: ");
		scanf_s("%d", &n);
	} while (n != 0);
	return 0;
}
void sort_ub(int * arr1)
{
	
	int obmen = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = sz - 1; j > i; j--)
		{
			if (*(arr1+j-1) < *(arr1+j))
			{
				obmen = *(arr1 + j - 1);
				*(arr1 + j - 1) = *(arr1 + j);
				*(arr1 + j) = obmen;
			}
		}
	}
}
void sort_vz(int * arr)
{
	
	int obmen = 0;
	for (int i = 0; i < sz; i++)
	{
		for (int j = sz - 1; j > i; j--)
		{
			if (*(arr + j - 1) > *(arr + j))
			{
				obmen = *(arr + j - 1);
				*(arr + j - 1) = *(arr + j);
				*(arr + j) = obmen;
			}
		}
	}
}
void F6(int * mass, int dl_mas, int &valp, int &valm, int &val0)
{
	valp = 0;
	valm = 0;
	val0 = 0;
	for (int i = 0; i < dl_mas; i++)
	{
		if (*(mass + i) == 0) val0++;
		if (*(mass + i) > 0) valp++;
		if (*(mass + i) < 0) valp++;
	}
}
void countEven(int * arr, int dl, int &cnt)
{
	cnt = 0;
	for (int i = 0; i < dl; i++)
	{
		if (*(arr + i) % 2 == 0) cnt++;
	}
}
void F9_max(double * mass, int dl,int *index)
{
	double max_val = 0;
	for (int i = 0; i < dl; i++)
	{
		if (*(mass + i) > max_val)
		{
			max_val = *(mass + i);
			*index = i;
		}
	}
}
void myStrLen(char * arr, int* dlina)
{
	int cnt = 0;
	do
	{
	  cnt++;
	} while (*(arr + cnt) != '\0');
	*dlina = cnt;

}

