#include <stdio.h>
using namespace std;
unsigned short a[305][22];
struct _d{
	unsigned short data;
	unsigned short now;
}d[22][305];
unsigned short answer[22];


int main()
{
	int n, m;
	int search;
    scanf("%d %d",&n,&m);
	for (int i=1, tmp1; i <= n; i++)
	{
		scanf("%d", &tmp1);
		for (int j=1; j <= m; j++) scanf("%d", &a[tmp1][j]);
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k <= j; k++)
			{
				if (d[i][j].data < d[i - 1][j - k].data + a[k][i])
				{
					d[i][j].data = d[i - 1][j - k].data + a[k][i];
					d[i][j].now = k;

				}
			}
		}
	}
	printf("%d\n", d[m][n].data);
	search = n;
	for (int i = m; i >= 1; i--)
	{
		answer[i] = d[i][search].now;
		search = search - answer[i];
	}
	for (int i = 1; i <= m; i++) printf("%d ",answer[i]);
	return 0;
}