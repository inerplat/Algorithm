#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;



class LCS{
public:
	int num;
	char trace;
	LCS() : num(0), trace(0) {}
};
LCS dp[1111][1111];
inline int max3(int x, int y, int z)
{
	if (x >= y && x >= z) return x;
	else if (y >= x && y >= z) return y;
	else return z;
}
int main()
{
	int n, m;
	int i, j;
	char set1[1111], set2[1111];
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
			dp[i][j].num = max3(x, y, z);
		}
	}
	cout << dp[n][m].num;
	return 0;
}