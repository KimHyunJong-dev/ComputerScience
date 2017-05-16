// MergeSort.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void MergeSort(int value[], int buffer[], int start, int end);
void mergeSortInternal(int value[], int buffer[], int start, int middle ,int end);


void mergeSortInternal(int values[], int buffer[], int start, int middle, int end)
{
	int i = start;
	int j = middle + 1;
	int k = start;
	int t = 0;

	// 분할 된 부분을 병합
	while (i <= middle && j <= end)
	{
		if (values[i] <= values[j])
		{
			buffer[k] = values[i];
			i++;
		}
		else
		{
			buffer[k] = values[j];
			j++;
		}

		k++;

	} //end of while



	// 병합 이후 처리
	if (i > middle)
	{
		for (t = j; t <= end; t++, k++)
		{
			buffer[k] = values[t];
		}
	}
	else
	{
		for (t = i; t <= middle; t++, k++)
		{
			buffer[k] = values[t];
		}
	}


	// 원래 배열에 데이터를 넣는 작업
	for (t = start; t <= end; t++) 
	{
		values[t] = buffer[t];
	}
}


void MergeSort(int values[], int buffer[], int start, int end)
{
	int middle = (start + end) / 2;

	if (start < end)
	{
		MergeSort(values, buffer, start, middle);
		MergeSort(values, buffer, middle+1,end);
		mergeSortInternal(values, buffer, start, middle, end);
	}

}


int main()
{
	//int values[] = { 80,75,10,60,15,49,12,25,11,19,100,26,88,45,54,87,98,66,51,78 };	
	int values[100] = { 0, };
	srand(time(NULL));

	for (int i = 0; i < 100; i++) {
		values[i] = rand() % 100;
	}

	int *pBuffer = NULL;
	pBuffer = (int *)malloc(sizeof(int) * sizeof(values) / sizeof(int) - 1);
		
	MergeSort(values, pBuffer, 0, sizeof(values) / sizeof(int) - 1);

	free(pBuffer);
		
	for (int j = 0; j < sizeof(values) / sizeof(int) - 1; j++) {
		printf("%4d", values[j]);
	}

	char ch;
	printf("\n아무키나 누루세요~");
	ch = cin.get();

    return 0;
}

