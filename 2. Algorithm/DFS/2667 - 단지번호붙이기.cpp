#include <cstdio>
#include <algorithm>
using namespace std;
int a[30][30], answer[999];
bool chk[30][30];
int ans[30][30];
char input[30];
int cnt;
void back(int r, int c)
{
	if (a[r + 1][c] && !chk[r + 1][c])
	{
		chk[r + 1][c] = 1;
		ans[r + 1][c] = cnt;
		back(r + 1, c);
	}
	if (a[r - 1][c] && !chk[r - 1][c])
	{
		chk[r - 1][c] = 1;
		ans[r - 1][c] = cnt;
		back(r - 1, c);
	}
	if (a[r][c + 1] && !chk[r][c + 1])
	{
		chk[r][c + 1] = 1;
		ans[r][c + 1] = cnt;
		back(r, c + 1);
	}
	if (a[r][c - 1] && !chk[r][c - 1])
	{
		chk[r][c - 1] = 1;
		ans[r][c - 1] = cnt;
		back(r, c - 1);
	}
}
int main()
{
	int n;
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		scanf("%s", &input[1]);
		for (j = 1; j <= n; j++) a[i][j] = input[j] - '0';
	}
	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			if (a[i][j] && !chk[i][j])
			{
				ans[i][j] = ++cnt;
				chk[i][j] = 1;
				back(i, j);
			}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (a[i][j]) ++answer[ans[i][j]];
		//	printf("%d ", ans[i][j]);
		}
		//printf("\n");
	}
	sort(&answer[1], &answer[cnt + 1]);
	printf("%d\n", cnt);
	for (i = 1; i <= cnt; i++) printf("%d\n", answer[i]);
	return 0;
}