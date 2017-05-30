// Factorial.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

// N! = 1*2*......N
// 6! = 720
// 8! = 40320
// 10! = 3628800

/*
���� 10872
0���� ũ�ų� ���� ���� N�� �־�����. �� ��, N!�� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� ���� N(0 �� N �� 12)�� �־�����.

���
ù° �ٿ� N!�� ����Ѵ�.
*/

#include <iostream>
using namespace std;

int factorial(int n) 
{
	if (n == 0) 
	{
		return 1;
	}

	else 
	{
		return n * factorial(n - 1);
	}
}

int main() {
	int n;
	cin >> n;
	cout << factorial(n) << '\n';
	return 0;
}