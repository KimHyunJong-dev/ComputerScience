// ModularArithmetic.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

// (A+B) mod M = ((A mod M) + (B mod M)) mod M
// (A*B) mod M = ((A mod M) * (B mod M)) mod M
// ������ ��� ���� mod ������ �� ��� �� ������ ���ü� �ֱ� ������ �Ʒ��� ���� �Ѵ�.
// (A-B) mod M = ((A mod M) - (B mod M) + M) mod M

/*
����
(A + B) % C��(A%C + B%C) % C �� ������ ?
(A��B)  % C��(A%C �� B%C) % C �� ������?
�� �� A, B, C�� �־����� ��, ���� �װ��� ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

�Է�
ù° �ٿ� A, B, C�� ������� �־�����. (2 �� A, B, C �� 10000)
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	
	cin >> a >> b >> c;

	a %= c;
	b %= c;

	// �Ʒ� �ΰ� �� ���� ����.
	cout << (a + b) % c << '\n';
	cout << (a % c + b % c)%c << '\n';

	// �Ʒ� �ΰ� �� ���� ����.
	cout << (a*b) % c << '\n';
	cout << (a % c * b % c) % c << '\n';

	char ch;
	ch = cin.get();
	cout << "�ƹ�Ű�� ���缼��~";
	
	return 0;
}
