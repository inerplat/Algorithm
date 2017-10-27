#include <cstdio>
#include <cstdlib>

class Team
{
public:
	int white;
	int black;
	void operator=(Team t)
	{
		white = t.white;
		black = t.black;
	}
};
inline int mymax(int x, int y) { return (x > y ? x : y); }
inline int mymax3(int x, int y, int z) { return(x >= y && x >= z ? x : y >= z && y >= x ? y : z); }
int d[1010][31][31];
Team chess[1010];
int main()
{
	int n,data;
	Team tmp;
//	freopen("input.txt", "r", stdin);
	for (n = 1; scanf("%d %d", &tmp.black, &tmp.white) != EOF; n++) chess[n] = tmp;
	for (int k = 1; k <= n; k++)
	{
		for (int i = 0; i <= 15; i++)
		{
			d[k][0][0] = d[k - 1][0][0];
			for (int j = 0; j <= 15; j++)
			{
				if(j==0) data = mymax(d[k - 1][i][j], d[k - 1][i - 1][j] + chess[k].black);
				else if(i==0) data = mymax(d[k - 1][i][j], d[k - 1][i][j - 1] + chess[k].white);
				else data = mymax3(d[k - 1][i][j], d[k - 1][i - 1][j] + chess[k].black, d[k - 1][i][j - 1] + chess[k].white);
				d[k][i][j] = data;
			}
		}
	}
	printf("%d", d[n-1][15][15]);
}
