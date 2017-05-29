// Questions_03.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제  9613
양의 정수 n개가 주어졌을 때, 가능한 모든 쌍의 GCD의 합을 구하는 프로그램을 작성하시오.

입력
첫째 줄에 테스트 케이스의 개수 t (1 < t < 100)이 주어진다. 
각 테스트 케이스는 한 줄로 이루어져 있고, 

첫째 줄에는 수의 개수 n (1 < n < 100)가 주어지고, 
다음에는 n개의 수가 주어진다. 입력으로 주어지는 수는 1000000을 넘지 않는다.

출력
각 테스트 케이스마다 가능한 모든 쌍의 GCD의 합을 출력한다.
*/

#include <cstdio>
int gcd(int x, int y) 
{
	if (y == 0) return x;
	else return gcd(y, x%y);
}

int main() {
	int t;
	scanf("%d", &t);

	while (t--) 
	{
		int a[111];
		int n;
		scanf("%d", &n);
	
		for (int i = 0; i<n; i++) scanf("%d", &a[i]);
		
		int sum = 0;
		for (int i = 0; i<n - 1; i++)
			for (int j = i + 1; j<n; j++)
				sum += gcd(a[i], a[j]);
		printf("%d\n", sum);
	}

	return 0;
}
