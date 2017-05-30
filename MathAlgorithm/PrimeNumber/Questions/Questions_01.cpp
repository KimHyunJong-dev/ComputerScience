// Questions_01.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
���� 1978
�־��� ���ڵ� �� �Ҽ��� �� ������ ã�Ƽ� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù �ٿ� ���� ���� N�� �־�����.N�� 100�����̴�.
�������� N���� ���� �־����µ� ���� 1, 000 ������ �ڿ����̴�.

���
�־��� ���� �� �Ҽ��� ������ ����Ѵ�.
*/


#include <iostream>
using namespace std;

bool is_prime(int x) 
{
	if (x < 2) 
	{
		return false;
	}

	for (int i = 2; i*i <= x; i++) 
	{
		if (x % i == 0) 
		{
			return false;
		}
	}
	return true;
}


int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i<n; i++) 
	{
		int num;
		cin >> num;
	
		if (is_prime(num)) 
		{
			cnt += 1;
		}
	}

	cout << cnt << '\n';
	return 0;
}