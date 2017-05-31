// A^B.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

// a�� b ������ ������ ���ؾ� �Ѵ�.
/*
int ans = 1;
for (int i = 1; i <= b; i++)
{
	ans = ans * a;
}
*/

// ���� ����� ������������ O(b) ��� �ð��� �ɸ��� �ȴ�.
// ���� ���� ���� ����� �ʿ��ϴ�.

//a�� 0 ������ ���
int calc(int a, int b)
{
	if (b == 0)  // a�� 0 ���� = 1
	{
		return 1;
	}
	else if (b == 1) // a�� b ���� = a
	{
		return a;
	}
	else if (b % 2 == 0) // a�� b ���� = a�� b ���� /2 * a�� b���� /2 (¦��)
	{
		// �Ʒ��� ���� ���� �ϸ� O(N). ȣ���� 2�谡 �Ǿ� ����.
		// return calc(a, b / 2) * calc(a, b / 2)
		// ���� �Ʒ��� ���� ���� ��.
		int temp = calc(a, b / 2);
		return temp * temp;
	}
	else // b % 2 ==1
	{
		return a* calc(a, b - 1); // a�� b ���� = a * a�� b���� -1 (Ȧ��)
	}
}

// ������ ������ ��� �ϴ� ���
int calc_01(int a, int b)
{
	int ans = 1;
	
	while (b > 0)
	{
		if (b % 2 == 1)
		{
			ans *= a;
		}
		a = a * a;
		b /= 2;
	}

	return ans;
}

