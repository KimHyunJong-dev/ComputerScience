// Factorial.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// N! = 1*2*......N
// 6! = 720
// 8! = 40320
// 10! = 3628800

/*
문제 10872
0보다 크거나 같은 정수 N이 주어진다. 이 때, N!을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 N(0 ≤ N ≤ 12)가 주어진다.

출력
첫째 줄에 N!을 출력한다.
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