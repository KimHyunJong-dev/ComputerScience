// Matrix.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

/* 
//
���� 10830  
ũ�Ⱑ N*N�� ��� A�� �־�����. �� ��, A�� B������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�. 
���� �ſ� Ŀ�� �� ������, A^B�� �� ���Ҹ� 1,000���� ���� �������� ����Ѵ�.

�Է�
ù° �ٿ� ����� ũ�� N�� B�� �־�����. (2 �� N ��  5, 1 �� B �� 100,000,000,000)

��° �ٺ��� N���� �ٿ� ����� �� ���Ұ� �־�����. ����� �� ���Ҵ� 1,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٺ��� N���� �ٿ� ���� ��� A�� B������ ����� ����Ѵ�.
*/

// ��� A�� B������ ���ϴ� ���� 

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


/*   ������� �Է� �޾Ƽ�  ��������
    for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			c[i][i] = a[i][j]+ b[i][j];

		}
	
	}
*/


/*   �� ����� �Է� �޾Ƽ�  ��������
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
