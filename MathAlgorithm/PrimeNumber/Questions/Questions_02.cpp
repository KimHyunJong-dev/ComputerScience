// Questions_02.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
/*
���� 1929
M�̻� N������ �Ҽ��� ��� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �ڿ��� M�� N�� �� ĭ�� ���̿� �ΰ� �־�����. (1��M��N��1, 000, 000)

���
�� �ٿ� �ϳ���, �����ϴ� ������� �Ҽ��� ����Ѵ�.
*/

#include <iostream>
using namespace std;
const int MAX = 1000000;

bool check[MAX + 1]; // true: ������, false: �������� ����

int main() 
{
	check[0] = check[1] = true;

	for (int i = 2; i*i <= MAX; i++) 
	{
		if (check[i] == false) 
		{
			for (int j = i + i; j <= MAX; j += i) 
			{
				check[j] = true;
			}
		}
	}

	int m, n;
	cin >> m >> n;

	for (int i = m; i <= n; i++) 
	{
		if (check[i] == false) 
		{
			cout << i << '\n';
		}
	}

	return 0;
}