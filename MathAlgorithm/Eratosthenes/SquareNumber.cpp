// SquareNumber.cpp : 嬬車 誓遂 覗稽益轡拭 企廃 遭脊繊聖 舛税杯艦陥.
//

#include "stdafx.h"

/*
庚薦  1016
嬢恐 呪 X亜 1左陥 笛 薦咽呪稽 蟹刊嬢 恭嬢走走 省聖 凶, 薦咽いい呪虞壱 廃陥.

薦咽呪澗 舛呪税 薦咽戚陥. min引 max亜 爽嬢走檎, 
min引 max研 匂敗廃 紫戚拭 薦咽いい呪亜 護 鯵 赤澗走 窒径廃陥.

脊径
湛属 匝拭 min引 max亜 爽嬢遭陥.min精 1左陥 滴暗蟹 旭壱, 
1, 000, 000, 000, 000左陥 拙暗蟹 旭精 切尻呪戚壱, 
max澗 min左陥 滴暗蟹 旭壱, min + 1, 000, 000左陥 拙暗蟹 旭精 切尻呪戚陥.

窒径
湛属 匝拭[min, max]姥娃拭 薦咽いい呪亜 護 鯵昔走 窒径廃陥
*/


// 社呪 : 2 ~ N-1 稽 蟹刊嬢 恭嬢走走 省澗 呪
// 薦咽 いい 呪: 2 * 2, 3 * 3 .. 薦咽呪稽 蟹刊嬢 恭嬢走走 省澗 呪.

// 社呪研 姥馬澗 号狛昔 拭虞塘什砺革什税 端研 誓遂 背辞 熱呪 赤陥.
// min - max 託戚亜 1,000,000 戚奄 凶庚拭 壕伸聖 戚遂拝呪 赤陥.

#include <cstdio>
bool check[1000001];
long long min, max;

int main() 
{
	// long long 生稽 脊径 閤澗陥.
	scanf("%lld %lld", &min, &max);

	// 薦咽 いい 呪 => 2*2, 3*3, 4*4
	for (long long i = 2; i*i <= max; i++) 
	{
		// 薦咽呪稽 蟹刊嬢 恭嬢走走 省澗 呪
		long long start = i*i - min % (i*i);
		if (start == i*i) 
		{
			start = 0;
		}
	
		//  拭虞塘什砺革什税 端 戚遂
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