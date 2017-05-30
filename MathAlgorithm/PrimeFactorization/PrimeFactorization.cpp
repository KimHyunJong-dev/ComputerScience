// PrimeFactorization.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.

#include "stdafx.h"

// 정수 N을 소수의 곱으로 분해.
// 소수를  구하지 않고 해결 가능.
// N을 소인수분해 했을때 나타날수 있는 
// 인수중에서 가장 큰값은 루트 N이다.
// 따라서 2부터 루트 N까지 for문을 돌면서 
// N을 나눌수 있으면, 나눌수 없을 때까지 계속 나누면 된다.

#include <iostream>
using namespace std;

/*
문제  11653
정수 N이 주어졌을 때, 소인수분해하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N (1 ≤ N ≤ 10,000,000)이 주어진다.

출력
N의 인수를 한 줄에 하나씩 증가하는 순서대로 출력한다.
*/


int main()
{
	//정수 N을 소수의 곱으로 분해.
	int n;
	cin >> n;

	// 2부터 루트 N까지 for문을 돌면서 
	for (int i = 2; i*i <= n; i++)
	{
		//나눌수 없을 때까지 계속 나누면 된다.
		while ( n % i == 0)
		{
			printf("%d\n", i);
			n /= i;
		}
	}

	if (n > 1)
	{
		printf("%d\n", n);
	}

    return 0;
}

