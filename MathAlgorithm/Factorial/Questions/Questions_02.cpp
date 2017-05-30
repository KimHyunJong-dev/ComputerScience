// Questions_02.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
���� 2004
nCm�� ���ڸ� 0�� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� n, m(0��m��n��2, 000, 000, 000, n != 0)�� ���´�.

���
ù° �ٿ� 0�� ������ ����Ѵ�.
*/

// nCm�� ���ڸ� 0�� ������ ���ϴ� ���� 
// n! / m!(n-m)!

// ���丮���� 2�ǰ����� 5�ǰ������� �׻� ���� ������ 5�� ������ ���� ��µ�
// ������ ��� ���� �𸣱� ������ 
// 2�ǰ��� �� 5�ǰ����� ���ÿ� ���� ��� �Ѵ�.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	long long two = 0, five = 0;
	long long n, m;
	cin >> n >> m;

	// n! / m!(n-m)!
	for (long long i = 2; i <= n; i *= 2) 
	{
		two += n / i;
	}

	for (long long i = 2; i <= n - m; i *= 2) 
	{
		two -= (n - m) / i;
	}
	for (long long i = 2; i <= m; i *= 2) 
	{
		two -= m / i;
	}


	for (long long i = 5; i <= n; i *= 5) 
	{
		five += n / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) 
	{
		five -= (n - m) / i;
	}

	for (long long i = 5; i <= m; i *= 5) 
	{
		five -= m / i;
	}

	cout << min(two, five) << '\n';
	return 0;
}