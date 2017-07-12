#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;



class LCS{
public:
	int num;
	char trace;
	LCS() : num(0), trace(0) {}
};
LCS dp[1111][1111];
/*
inline int max3(int x, int y, int z)
{
	if (x >= y && x >= z) return x;
	else if (y >= x && y >= z) return y;
	else return z;
}
*/
int main()
{
	int n, m;
	int i, j;
	char set1[1111], set2[1111], answer[1111];
	scanf("%s\n%s", &set1[1], &set2[1]);
	n = strlen(&set1[1]);
	m = strlen(&set2[1]);
	int x, y, z;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			x = dp[i - 1][j].num;
			y = dp[i][j - 1].num;
			if (set1[i] == set2[j]) z = dp[i - 1][j - 1].num + 1;
			else z = dp[i - 1][j - 1].num;
		//	dp[i][j].num = max3(x, y, z);
			if (x >= y && x >= z)
			{
				dp[i][j].num = x;
				dp[i][j].trace = 1;
			}
			else if (y >= x && y >= z)
			{
				dp[i][j].num = y;
				dp[i][j].trace = 2;
			}
			else
			{
				dp[i][j].num = z;
				dp[i][j].trace = 3;
			}
		}
	}
	cout << dp[n][m].num << endl;
	i = n; j = m;
	int cnt = 0;
	while (i != 0 && j != 0)
	{
		if (dp[i][j].trace == 1) i--;
		else if (dp[i][j].trace == 2) j--;
		else {
			if (dp[i][j].num != dp[i - 1][j - 1].num) answer[++cnt] = set1[i];
			i--; j--;
		}
	}
	for (i = cnt; i >= 1; i--)
	{
		printf("%c", answer[i]);
	}
	return 0;
}