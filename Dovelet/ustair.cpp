#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

int dp1[330];
int dp2[330];
int dat[330];
inline int max(int x, int y) { return (x > y ? x : y); }

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &dat[i]);

	dp1[1] = dat[1];
	for (int i = 2; i <= n; i++)
	{
		dp1[i] = max(dp1[i - 2] + dat[i], dp2[i - 2] + dat[i]);
		dp2[i] = dp1[i - 1] + dat[i];
	}

	printf("%d", max(dp1[n], dp2[n]));
	return 0;
}
