// Questions_01.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/*
문제 1676

N!에서 뒤에서부터 처음 0이 아닌 숫자가 나올 때까지 
0의 개수를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. (0 ≤ N ≤ 500)

출력
첫째 줄에 구한 0의 개수를 출력한다.
*/


// N! 0의 개수를 구하려면 N!을 인수분해 했을때
// 2와 5가 몇개 나오는지 알아야 한다.
// 하지만 5의 개수가 항상 2의 개수 보다 적기 때문에 5의 개수만 세어 주면 된다.

#include <iostream>
using namespace std;
int main() 
{
	int ans = 0;
	int n;

	cin >> n;

	for (int i = 5; i <= n; i *= 5) 
	{
		ans += n / i;
	}

	cout << ans << '\n';

	return 0;
}