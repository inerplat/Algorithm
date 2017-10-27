#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

int d[110][110], flower[110][110];

inline int mymax(int x, int y) { return (x > y ? x : y); }

int main()
{
	int max;
	int i, j, n, m;
	scanf("%d %d", &n, &m);
	fill(&d[0][0], &d[110][110 + 1], -2e9);
	for (i = 1; i <= n; i++) for (j = 1; j <= m; j++) scanf("%d", &flower[i][j]);
	memcpy(&d[1][0], &flower[1][0], sizeof(flower[1]));
	max = d[1][1];
	for (i = 2; i <= m; i++) d[1][i] = max = d[1][i] > max ? d[1][i] : max;
	for (i = 2; i <= n; i++) for (j = i; j <= m; j++) d[i][j] = mymax(d[i - 1][j - 1] + flower[i][j], d[i][j - 1]);
	printf("%d", d[n][m]);
}
