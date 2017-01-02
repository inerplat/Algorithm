#include <iostream>
using namespace std;


int main()
{
	int n;
	int a[1010][4];
	int dp[1010][4] = { 2147483647 };
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i][1] >> a[i][2] >> a[i][3];
	dp[1][1] = a[1][1];
	dp[1][2] = a[1][2];
	dp[1][3] = a[1][3];
	for (int i = 2; i <= n; i++)
	{
		dp[i][1] = (dp[i - 1][2] + a[i][1] < dp[i - 1][3] + a[i][1]) ? dp[i - 1][2] + a[i][1] : dp[i - 1][3] + a[i][1];
		dp[i][2] = (dp[i - 1][1] + a[i][2] < dp[i - 1][3] + a[i][2]) ? dp[i - 1][1] + a[i][2] : dp[i - 1][3] + a[i][2];
		dp[i][3] = (dp[i - 1][1] + a[i][3] < dp[i - 1][2] + a[i][3]) ? dp[i - 1][1] + a[i][3] : dp[i - 1][2] + a[i][3];
	}
	cout << ((dp[n][1] <= dp[n][2] && dp[n][1] <= dp[n][3]) ? dp[n][1] : (dp[n][2] <= dp[n][1] && dp[n][2] <= dp[n][3]) ? dp[n][2] : dp[n][3]);
	return 0;
}