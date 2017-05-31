// EulerPhiFunction.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제  11689
자연수 n이 주어졌을 때, GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 자연수 n (1 ≤ n ≤ 1012)이 주어진다.

출력
GCD(n, k) = 1을 만족하는 자연수 1 ≤ k ≤ n 의 개수를 출력한다.
*/

#include <iostream>
using namespace std;

// 오일러 피 함수
long long phi(long long n) 
{
	long long ans = n;

	for (long long i = 2; i*i <= n; i++) 
	{
		if (n % i == 0) 
		{
			while (n % i == 0) 
			{
				n /= i;
			}
			ans -= ans / i;
		}
	}

	if (n > 1)
		ans -= ans / n;

	return ans;
}


int main() 
{
	long long n;
	cin >> n;
	cout << phi(n) << '\n';
	return 0;
}