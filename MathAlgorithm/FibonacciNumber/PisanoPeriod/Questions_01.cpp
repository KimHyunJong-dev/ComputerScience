// Questions_01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제 2749
피보나치 수는 0과 1로 시작한다. 
0번째 피보나치 수는 0이고, 1번째 피보나치 수는 1이다. 
그 다음 2번째 부터는 바로 앞 두 피보나치 수의 합이 된다.

이를 식으로 써보면 Fn = Fn-1 + Fn-2 (n>=2)가 된다.

n=17일때 까지 피보나치 수를 써보면 다음과 같다.

0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597

n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 n이 주어진다. 
n은 1,000,000,000,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 n번째 피보나치 수를 1,000,000으로 나눈 나머지를 출력한다.
*/


// N번째 피보나치 수를 M= 1,000,000 으로 나눈 나머지를 구하는 문제 
// N <= 1,000,000,000,000,000,000

// 피보나치 수를 N으로 나눈 나머지는 주기를 갖는다. 이를 피사노 주기라고 한다.
// 피사노 주기를 이용해서 주기를 찾고 문제를 풀수 있다.

// 주기의 길이가 K이면 
// N 번째 피보나치 수를 M 으로 나눈 나머지는 N%K 번째 피보나치 수와 같다.
// M = 10의 k 제곱일 때, K > 2라면 주기는 항상 15*10의k-1 이다. 

#include <iostream>
using namespace std;

long long d[1500000];

int main() 
{
	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i<1500000; i++) 
	{
		d[i] = d[i - 1] + d[i - 2];
		d[i] %= 1000000;
	}

	long long n;
	cin >> n;
	cout << d[n % 1500000] << '\n';

	return 0;
}
