// Questions_03.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
����  9613
���� ���� n���� �־����� ��, ������ ��� ���� GCD�� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� �׽�Ʈ ���̽��� ���� t (1 < t < 100)�� �־�����. 
�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ְ�, 

ù° �ٿ��� ���� ���� n (1 < n < 100)�� �־�����, 
�������� n���� ���� �־�����. �Է����� �־����� ���� 1000000�� ���� �ʴ´�.

���
�� �׽�Ʈ ���̽����� ������ ��� ���� GCD�� ���� ����Ѵ�.
*/

#include <cstdio>
int gcd(int x, int y) 
{
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) 
	{
		int a[111];
		int n;
		scanf("%d", &n);
	
		for (int i = 0; i<n; i++) scanf("%d", &a[i]);
		
		int sum = 0;
		for (int i = 0; i<n - 1; i++)
			for (int j = i + 1; j<n; j++)
				sum += gcd(a[i], a[j]);
		printf("%d\n", sum);
	}

	return 0;
}
