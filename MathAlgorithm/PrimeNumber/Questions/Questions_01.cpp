// Questions_01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제 1978
주어진 숫자들 중 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

입력
첫 줄에 수의 개수 N이 주어진다.N은 100이하이다.
다음으로 N개의 수가 주어지는데 수는 1, 000 이하의 자연수이다.

출력
주어진 수들 중 소수의 개수를 출력한다.
*/


#include <iostream>
using namespace std;

bool is_prime(int x) 
{
	if (x < 2) 
	{
		return false;
	}

	for (int i = 2; i*i <= x; i++) 
	{
		if (x % i == 0) 
		{
			return false;
		}
	}
	return true;
}


int main() {
	int n;
	cin >> n;

	int cnt = 0;
	for (int i = 0; i<n; i++) 
	{
		int num;
		cin >> num;
	
		if (is_prime(num)) 
		{
			cnt += 1;
		}
	}

	cout << cnt << '\n';
	return 0;
}