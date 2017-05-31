// FibonacciNubmer.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

//  Fn = Fn-1 + Fn-2 (n>=2)�� �ȴ�.
// n=17�϶� ���� �Ǻ���ġ ���� �Ẹ�� ������ ����.
// 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
// n�� 90���� �۰ų� ���� �ڿ������� �Ѵ�. int ������ �Ѿ� ���� �����̴�.

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

