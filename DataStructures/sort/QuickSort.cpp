// QuickSort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void QuickSort(int *array, int start, int end);
void swap(int * a, int * b);

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void QuickSort(int *array, int start, int end)
{
	if (start >= end) { return; }

	int middle = (start + end) / 2;
	int pivot = array[middle];

	int left = start;
	int right = end;

	swap(&array[start], &array[middle]);

	while (true) {

		while (array[left] <= pivot) { left++;  }
		while (array[right] > pivot) { right--; }

		if (left > right) break;

		swap(&array[left], &array[right]);
	}

	swap(&array[start], &array[right]);

	QuickSort(array, start, right - 1);

	QuickSort(array, right + 1, end);

	return;
}



int main()
{
	//int values[] = { 80,75,10,60,15,49,12,25,11,19,100,26,88,45,54,87,98,66,51,78 };
	int values[100] = { 0, };

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		values[i] = rand() % 100;
	}

	QuickSort(values, 0, sizeof(values) / sizeof(int) - 1);

	for (int j = 0; j < sizeof(values) / sizeof(int) - 1; j++) {
		printf("%4d", values[j]);
	}

	char ch;
	printf("아무키나 누루세요\n");
	ch = cin.get();

	return 0;
}



/*
void QuickSort(int array[], int start, int end);
int partitionQuickSort(int value[], int start, int end);


int partitionQuickSort(int value[], int start, int end)
{

	//int mid = (start + end) / 2;
	//int pivot = value[mid];

	int pivot = end;	
	int right = end;
	int left  = start;
	int temp = 0;

	while ( left < right )
	{
		// 왼쪽 집합.. pivot보다 큰 값을 찾는다.
		while ( (value[left] < value[pivot]) && (left < right) )   
		{ 
			left++;  
		}
		
		// 오른쪽 집합.. pivot보다 작거나 같은 녀석을 찾는다.
		while ( (value[right] >= value[pivot]) && (left < right) ) 
		{ 
			right--; 
		}

		if (left < right) 
		{

			temp = value[left];
			value[left] = value[right];
			value[right] = temp;
		}		

	}// end of while

	temp = value[pivot];
	value[pivot] = value[right];
	value[right] = temp;

	return right;
}


void QuickSort(int value[], int start, int end)
{
	int pivot = 0;

	if (start < end)
	{
		pivot = partitionQuickSort(value, start, end);
		QuickSort(value, start, pivot - 1);
		QuickSort(value, pivot + 1, end);
	}
}


int main()
{
	//int values[] = {80,75,10,60,15,49,12,25,11,19,100,26,88,45,54,87,98,66,51,78};

	int values[100] = { 0, };

	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		values[i] = rand() % 100;
	}

	QuickSort(values, 0, sizeof(values) / sizeof(int) - 1);


	for (int j = 0; j < sizeof(values) / sizeof(int); j++) {
		printf("%4d", values[j]);
	}

	char ch;
	printf("아무키나 누루세요\n");
	ch = cin.get();

	return 0;
}*/

