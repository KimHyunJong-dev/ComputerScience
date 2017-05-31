// SquareNumber.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제  1016
어떤 수 X가 1보다 큰 제곱수로 나누어 떨어지지 않을 때, 제곱ㄴㄴ수라고 한다.

제곱수는 정수의 제곱이다. min과 max가 주어지면, 
min과 max를 포함한 사이에 제곱ㄴㄴ수가 몇 개 있는지 출력한다.

입력
첫째 줄에 min과 max가 주어진다.min은 1보다 크거나 같고, 
1, 000, 000, 000, 000보다 작거나 같은 자연수이고, 
max는 min보다 크거나 같고, min + 1, 000, 000보다 작거나 같은 자연수이다.

출력
첫째 줄에[min, max]구간에 제곱ㄴㄴ수가 몇 개인지 출력한다
*/


// 소수 : 2 ~ N-1 로 나누어 떨어지지 않는 수
// 제곱 ㄴㄴ 수: 2 * 2, 3 * 3 .. 제곱수로 나누어 떨어지지 않는 수.

// 소수를 구하는 방법인 에라토스테네스의 체를 응용 해서 풀수 있다.
// min - max 차이가 1,000,000 이기 때문에 배열을 이용할수 있다.

#include <cstdio>
bool check[1000001];
long long min, max;

int main() 
{
	// long long 으로 입력 받는다.
	scanf("%lld %lld", &min, &max);

	// 제곱 ㄴㄴ 수 => 2*2, 3*3, 4*4
	for (long long i = 2; i*i <= max; i++) 
	{
		// 제곱수로 나누어 떨어지지 않는 수
		long long start = i*i - min % (i*i);
		if (start == i*i) 
		{
			start = 0;
		}
	
		//  에라토스테네스의 체 이용
		for (long long j = start; j <= max - min; j += i*i) 
		{
			check[j] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i <= max - min; i++) 
	{
		if (check[i] == 0) 
		{
			ans++;
		}
	}

	printf("%d\n", ans);
	return 0;
}