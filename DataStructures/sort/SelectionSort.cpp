// SelectionSort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using namespace std;
using std::cin;

void DataPrint(int value[], int count);
void SelectionSort(int value[], int count);

int main()
{
	//int array [] = { 80,75,10,60,15,49,12,25,11,19,100,26,88,45,54,87,98,66,51,78 };

	int array[100] = { 0, };

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		array[i] = rand() % 100;
	}


	SelectionSort(array, 20);

	char ch;	
	printf("\n아무키나 누루세요~");
	ch = cin.get();

	return 0;
}


void SelectionSort(int value[], int count)
{
	//int i = 0, j = 0;
	int temp = 0, min_value = 0;

	for (int cur_index = 0; cur_index < count - 1; cur_index++)
	{
		min_value = cur_index;

		for (int j = cur_index + 1; j < count; j++)
		{
			if (value[j] < value[min_value])
			{
				min_value = j;
			}
		}

		temp = value[cur_index];
		value[cur_index] = value[min_value];
		value[min_value] = temp;

	} // end of for

	DataPrint(value, 20);

}

void DataPrint(int value[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", value[i]);
	}
}
