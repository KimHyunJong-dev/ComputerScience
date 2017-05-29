// ModularArithmetic.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// (A+B) mod M = ((A mod M) + (B mod M)) mod M
// (A*B) mod M = ((A mod M) * (B mod M)) mod M
// 뺄쎔의 경우 먼저 mod 연산을 한 결과 가 음수가 나올수 있기 때문에 아래와 같이 한다.
// (A-B) mod M = ((A mod M) - (B mod M) + M) mod M

/*
문제
(A + B) % C는(A%C + B%C) % C 와 같을까 ?
(A×B)  % C는(A%C × B%C) % C 와 같을까?
세 수 A, B, C가 주어졌을 때, 위의 네가지 값을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 A, B, C가 순서대로 주어진다. (2 ≤ A, B, C ≤ 10000)
*/

#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	
	cin >> a >> b >> c;

	a %= c;
	b %= c;

	// 아래 두개 의 값이 같다.
	cout << (a + b) % c << '\n';
	cout << (a % c + b % c)%c << '\n';

	// 아래 두개 의 값이 같다.
	cout << (a*b) % c << '\n';
	cout << (a % c * b % c) % c << '\n';

	char ch;
	ch = cin.get();
	cout << "아무키나 누루세요~";
	
	return 0;
}
