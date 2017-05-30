// Questions_02.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제 2004
nCm의 끝자리 0의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 정수 n, m(0≤m≤n≤2, 000, 000, 000, n != 0)이 들어온다.

출력
첫째 줄에 0의 개수를 출력한다.
*/

// nCm의 끝자리 0의 개수를 구하는 문제 
// n! / m!(n-m)!

// 팩토리얼은 2의개수가 5의개수보다 항상 많기 때문에 5의 개수만 세워 줬는데
// 조합은 어떻게 될지 모르기 때문에 
// 2의개수 와 5의개수를 동시에 세어 줘야 한다.

#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	long long two = 0, five = 0;
	long long n, m;
	cin >> n >> m;

	// n! / m!(n-m)!
	for (long long i = 2; i <= n; i *= 2) 
	{
		two += n / i;
	}

	for (long long i = 2; i <= n - m; i *= 2) 
	{
		two -= (n - m) / i;
	}
	for (long long i = 2; i <= m; i *= 2) 
	{
		two -= m / i;
	}


	for (long long i = 5; i <= n; i *= 5) 
	{
		five += n / i;
	}
	for (long long i = 5; i <= n - m; i *= 5) 
	{
		five -= (n - m) / i;
	}

	for (long long i = 5; i <= m; i *= 5) 
	{
		five -= m / i;
	}

	cout << min(two, five) << '\n';
	return 0;
}