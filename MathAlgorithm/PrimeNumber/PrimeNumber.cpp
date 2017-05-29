// PrimeNumber.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* 소수 구하기 (일반적인 방법)
약수가 1 과 자기 자신 밖에 없는 수를 소수라 함.

N 이 소수가 되려면, 2보다 크거나 같고,
N-1 보다 작거나 같은 자연수로 나누어 떨어 지면 안된다.

O(N 시간 걸림)
*/

bool prime(int n)
{
	if (n < 2)
	{
		return false;
	}

	for(int i = 2; i < n-1; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}



/* 소수 구하기 update 01
약수가 1 과 자기 자신 밖에 없는 수를 소수라 함.
N 이 소수가 되려면, 2 보다 크거나 같고,
N/2 보다 작거나 같은 자연수로 나누어 떨어 지면 안된다
이유: N의 약수 중에서 가장 큰것은 N/2보다 작거나 같기 때문

N = a * b 로 나타낼수 있는데, a 가 작을수록  b는 크다.
가능한 a중 에서 가장 작은 값은 2이기 때문에 b는 N/2를 넘지 않는다.
O(N ) 시간 걸림
*/

bool primeUpdate01(int n)
{
	if (n < 2)
	{
		return false;
	}

	for (int i = 2; i <= n /2; i++)
	{
		if ( n % i == 0)
		{
			return false;
		}
	}
	return true;
}

/* 소수 구하기 update 02
약수가 1 과 자기 자신 밖에 없는 수를 소수라 함.

N 이 소수가 되려면, 2 보다 크거나 같고,
루트N 보다 작거나 같은 자연수로 나누어 떨어지면 안된다

이유: N이 소수가 아니라면 N = a * b 로 나타낼수 있다. ( a <= b )

a > b 라면 두수를 바꿔서 항상 a <= b 로 만들수 있다.
두 수 a 와 b 의 차이가 가장 작은 경우는 루트N 이다.
따라서, 루트까지만 검사를 해보면 된다.

그러니까
루트N 은 i <= N * N 과 같다.

언제나 O(루트N) 시간 걸림

*/

bool primeUpdate02(int n)
{
	if (n < 2)
	{
		return false;
	}

	for (int i = 2; i * i <= n; i++)
	{
		if ( n % i == 0)
		{
			return false;
		}
	}
	return true;
}

