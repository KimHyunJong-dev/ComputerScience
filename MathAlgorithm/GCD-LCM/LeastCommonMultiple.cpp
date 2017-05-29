// Least Common Multiple.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// 두 수 A 와 B 의 최대공배수 l은
// A 와 B 의 공통된 배수 중에서 가장 작은 정수이다.

// 최대공배수는 gcd 를 응용해서 구 할 수 있다
// 두 수 a, b 의 최대 공약수를  g라고 했을때 
// 최소공배수 l = g * (a/g) * (b/g) 이다.

#include <iostream>
using namespace std;

// 최대 공약수
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
	
		// 최대 공약수를 구한다.
		int g = gcd(a, b);
		
		// 최대 공베수를 구한다.
		cout << a*b / g << '\n';
	}
	return 0;
}
