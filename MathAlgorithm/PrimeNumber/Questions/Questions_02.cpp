// Questions_02.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
/*
문제 1929
M이상 N이하의 소수를 모두 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 M과 N이 빈 칸을 사이에 두고 주어진다. (1≤M≤N≤1, 000, 000)

출력
한 줄에 하나씩, 증가하는 순서대로 소수를 출력한다.
*/

#include <iostream>
using namespace std;
const int MAX = 1000000;

bool check[MAX + 1]; // true: 지워짐, false: 지워지지 않음

int main() 
{
	check[0] = check[1] = true;

	for (int i = 2; i*i <= MAX; i++) 
	{
		if (check[i] == false) 
		{
			for (int j = i + i; j <= MAX; j += i) 
			{
				check[j] = true;
			}
		}
	}

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) 
	{
		if (check[i] == false) 
		{
			cout << i << '\n';
		}
	}

	return 0;
}