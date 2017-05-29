// Least Common Multiple.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

// �� �� A �� B �� �ִ����� l��
// A �� B �� ����� ��� �߿��� ���� ���� �����̴�.

// �ִ������� gcd �� �����ؼ� �� �� �� �ִ�
// �� �� a, b �� �ִ� �������  g��� ������ 
// �ּҰ���� l = g * (a/g) * (b/g) �̴�.

#include <iostream>
using namespace std;

// �ִ� �����
int gcd(int x, int y) 
{
	if (y == 0) 
		return x;

	else return gcd(y, x%y);
}

int main() {
	int t;
	cin >> t;

	while (t--) {
	
		int a, b;
		cin >> a >> b;
	
		// �ִ� ������� ���Ѵ�.
		int g = gcd(a, b);
		
		// �ִ� �������� ���Ѵ�.
		cout << a*b / g << '\n';
	}
	return 0;
}
