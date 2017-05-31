// Matrix.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"

/* 
//
문제 10830  
크기가 N*N인 행렬 A가 주어진다. 이 때, A의 B제곱을 구하는 프로그램을 작성하시오. 
수가 매우 커질 수 있으니, A^B의 각 원소를 1,000으로 나눈 나머지를 출력한다.

입력
첫째 줄에 행렬의 크기 N과 B가 주어진다. (2 ≤ N ≤  5, 1 ≤ B ≤ 100,000,000,000)

둘째 줄부터 N개의 줄에 행렬의 각 원소가 주어진다. 행렬의 각 원소는 1,000보다 작거나 같은 자연수 또는 0이다.

출력
첫째 줄부터 N개의 줄에 걸쳐 행렬 A를 B제곱한 결과를 출력한다.
*/

// 행렬 A의 B제곱을 구하는 문제 

#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> matrix_multiplication(vector<vector<int>> &a, vector<vector<int>> &b) 
{
	int n = a.size();
	vector<vector<int>> c(n, vector<int>(n));
	
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++) 
		{
			for (int k = 0; k<n; k++) 
			{
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= 1000;
		}
	}
	return c;
}

int main() 
{
	int n;
	long long b;

	cin >> n >> b;

	vector<vector<int>> ans(n, vector<int>(n));
	vector<vector<int>> a(n, vector<int>(n));

	for (int i = 0; i<n; i++) 
	{
		for (int j = 0; j<n; j++) 
		{
			cin >> a[i][j];
		}
		ans[i][i] = 1;
	}

	while (b > 0) 
	{
		if (b % 2 == 1) 
		{
			ans = matrix_multiplication(ans, a);
		}
		
		a = matrix_multiplication(a, a);
		b /= 2;
	}

	for (int i = 0; i<ans.size(); i++) 
	{
		for (int j = 0; j<ans[i].size(); j++) 
		{
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}


/*   두행렬을 입력 받아서  덧셈수행
    for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			c[i][i] = a[i][j]+ b[i][j];

		}
	
	}
*/


/*   두 행렬을 입력 받아서  곱셈수행
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<r; j++)
		{
		   c[i][j] = 0;
		   for(int k = 0; k < m; k++)
		   {
			  c[i][j] += a[i][k] * b[k][j];
	       }

		}

	}
*/
