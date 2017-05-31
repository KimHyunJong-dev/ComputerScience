// Questions_01.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
����  1629
�ڿ��� A�� B�� ���� ���� �˰� �ʹ�.
�� ���Ϸ��� ���� �ſ� Ŀ�� �� �����Ƿ� �̸� C�� ���� �������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A, B, C�� �� ĭ�� ���̿� �ΰ� ������� �־�����.
A, B, C�� ��� 2, 147, 483, 647 ������ �ڿ����̴�.

���
ù° �ٿ� A�� B�� ���� ���� C�� ���� �������� ����Ѵ�.
*/


// (A*B)%C = (A % C * B % C) % C �̴�.

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


// ������ ���� 
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
