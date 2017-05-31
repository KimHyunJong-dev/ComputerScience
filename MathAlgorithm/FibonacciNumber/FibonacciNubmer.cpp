// FibonacciNubmer.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

//  Fn = Fn-1 + Fn-2 (n>=2)가 된다.
// n=17일때 까지 피보나치 수를 써보면 다음과 같다.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
// n은 90보다 작거나 같은 자연수여야 한다. int 번위를 넘어 가기 때문이다.

int fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}


int dp[100] = {0};
int fibonacci_01(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		if (dp[n] > 0)
		{
			return dp[n];
		}

		dp[n] =  fibonacci_01(n - 1) + fibonacci_01(n - 2);
		return dp[n];
	}
}


int main()
{
	fibonacci(45);     // O(n)
	fibonacci_01(45); // O(1)
    return 0;
}

