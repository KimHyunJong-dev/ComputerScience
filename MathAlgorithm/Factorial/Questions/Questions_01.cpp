// Questions_01.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/*
���� 1676

N!���� �ڿ������� ó�� 0�� �ƴ� ���ڰ� ���� ������ 
0�� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� N�� �־�����. (0 �� N �� 500)

���
ù° �ٿ� ���� 0�� ������ ����Ѵ�.
*/


// N! 0�� ������ ���Ϸ��� N!�� �μ����� ������
// 2�� 5�� � �������� �˾ƾ� �Ѵ�.
// ������ 5�� ������ �׻� 2�� ���� ���� ���� ������ 5�� ������ ���� �ָ� �ȴ�.

#include <iostream>
using namespace std;
int main() 
{
	int ans = 0;
	int n;

	cin >> n;

	for (int i = 5; i <= n; i *= 5) 
	{
		ans += n / i;
	}

	cout << ans << '\n';

	return 0;
}