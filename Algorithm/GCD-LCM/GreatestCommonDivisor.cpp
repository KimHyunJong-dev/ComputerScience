// Greatest_Common_Divisor.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

// 두 수 A 와 B 의 최대 공약수 G는
// A 와 B 의 공통된 약수 중에서 가장 큰 정수이다.
// 최대 공약수를 구하는 가장 쉬운 방법은 2부터 
// min(A,B)까지 그러니까 두 수중에서 제일 작은수로 
// 모든 정수로 나누어 보는 방법이 있다
// 이때 최대 공약수가 1인 두수를 서로소 라고 한다.
// O(N) 시간 걸린다.
// gcd_01 예제 참고  

/*
int gcd_01(int a, int b)
{
	int g = 1;
	for (int i = 2; i <= min(a, b); i++)
	{
		if (a % i == 0 && b % i == 0)
		{
			g = i;
		}
	}

	return g;
}
*/


// 유클리드 호제법을 사용한 방법.
// A를 B로 나눈 다음 나머지를 R이라고 했을때
// GCD(a,b) = GCD(b, a%b) 즉, GCD(b,r)과 같다.
// R이 0이면 그때 B가 최대공약수 있다.
// GCD(24,16) = GCD(16,8) = GCD(8,0) = 8;
// 최대 공약수는 8!!

// 재귀 함수
int gcd_02(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return gcd_02(b, a%b);
	}
}

// 비 재귀
int gcd_03(int a, int b)
{
	while (b != 0)
	{
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

// 위 알고리즘으로 
// 세수의 최대 공약수를 다음과 같이 구할수 있다
// GCD(a,b,c) = GCD(GCD(a,b) c)
// N 개의 숫자도 동일 하게 구할수 있다.
int main()
{
	gcd_02(24, 16);

	gcd_03(80, 40);

	return 0;
}

