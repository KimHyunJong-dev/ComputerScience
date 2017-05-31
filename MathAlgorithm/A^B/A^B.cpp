// A^B.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// a의 b 제곱을 빠르게 구해야 한다.
/*
int ans = 1;
for (int i = 1; i <= b; i++)
{
	ans = ans * a;
}
*/

// 위의 방법은 직관적이지만 O(b) 라는 시간이 걸리게 된다.
// 따라서 조금 빠른 방법이 필요하다.

//a의 0 제곱을 계산
int calc(int a, int b)
{
	if (b == 0)  // a의 0 제곱 = 1
	{
		return 1;
	}
	else if (b == 1) // a의 b 제곱 = a
	{
		return a;
	}
	else if (b % 2 == 0) // a의 b 제곱 = a의 b 제곱 /2 * a의 b제곱 /2 (짝수)
	{
		// 아래와 같이 구현 하면 O(N). 호출이 2배가 되어 버림.
		// return calc(a, b / 2) * calc(a, b / 2)
		// 따라서 아래와 같이 구현 함.
		int temp = calc(a, b / 2);
		return temp * temp;
	}
	else // b % 2 ==1
	{
		return a* calc(a, b - 1); // a의 b 제곱 = a * a의 b제곱 -1 (홀수)
	}
}

// 이진수 원리로 계산 하는 방법
int calc_01(int a, int b)
{
	int ans = 1;
	
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			ans *= a;
		}
		a = a * a;
		b /= 2;
	}

	return ans;
}

