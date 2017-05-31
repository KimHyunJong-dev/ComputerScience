// EulerPhiFunction.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
����  11689
�ڿ��� n�� �־����� ��, GCD(n, k) = 1�� �����ϴ� �ڿ��� 1 �� k �� n �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� n (1 �� n �� 1012)�� �־�����.

���
GCD(n, k) = 1�� �����ϴ� �ڿ��� 1 �� k �� n �� ������ ����Ѵ�.
*/

#include <iostream>
using namespace std;

// ���Ϸ� �� �Լ�
long long phi(long long n) 
{
	long long ans = n;

	for (long long i = 2; i*i <= n; i++) 
	{
		if (n % i == 0) 
		{
			while (n % i == 0) 
			{
				n /= i;
			}
			ans -= ans / i;
		}
	}

	if (n > 1)
		ans -= ans / n;

	return ans;
}


int main() 
{
	long long n;
	cin >> n;
	cout << phi(n) << '\n';
	return 0;
}