// Questions_01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제  1629
자연수 A를 B번 곱한 수를 알고 싶다.
단 구하려는 수가 매우 커질 수 있으므로 이를 C로 나눈 나머지를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 빈 칸을 사이에 두고 순서대로 주어진다.
A, B, C는 모두 2, 147, 483, 647 이하의 자연수이다.

출력
첫째 줄에 A를 B번 곱한 수를 C로 나눈 나머지를 출력한다.
*/


// (A*B)%C = (A % C * B % C) % C 이다.

#include <iostream>
using namespace std;

long long mul(long long a, long long b, long long c) 
{
	if (b == 0) 
	{
		return 1LL;
	}
	else if (b == 1) 
	{
		return a%c;
	}
	else if (b % 2 == 0) 
	{
		long long temp = mul(a, b / 2, c);
		return (temp * temp) % c;
	}
	else 
	{
		return (a * mul(a, b - 1, c)) % c;
	}
}


// 이진수 응용 
long long mul_01(long long a, long long b, long long c) 
{
	long long ans = 1LL;

	while (b > 0) 
	{
		if (b % 2 == 1) 
		{
			ans *= a;
			ans %= c;
		}

		b /= 2;
		a = a * a;
		a %= c;
	}

	return ans;
}

int main() 
{
	long long a, b, c;

	cin >> a >> b >> c;

	cout << mul(a, b, c) << '\n';

	return 0;
}
