#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;
class MINSICK {
public:
	int city, cost;
};
vector <MINSICK> d[110];
bool link[111][111];
int vertex[111];
long long cost[111];
int main()
{
	int n, s, f, m;
	int i, j, k;
	scanf("%d %d %d %d", &n, &s, &f, &m);
	for (i = 0; i < m; i++)
	{
		int tmp1;
		MINSICK tmp2;
		scanf("%d %d %d", &tmp1, &tmp2.city, &tmp2.cost);
		d[tmp1].push_back(tmp2);
		link[tmp1][tmp2.city] = 1;
	}
	for (i = 0; i < n; i++) scanf("%d", &vertex[i]);
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (i == j || (link[i][k] && link[k][j])) link[i][j] = 1;
			}
		}
	}
	fill(cost, cost + n, 1e18 * 9);
	cost[s] = -vertex[s];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (k = 0; k < d[j].size(); k++)
			{
				if (cost[j] != 1e18 * 9 && cost[d[j][k].city] > cost[j] + d[j][k].cost - vertex[d[j][k].city])
				{
					cost[d[j][k].city] = cost[j] + d[j][k].cost - vertex[d[j][k].city];

					if (i == n - 1 && link[d[j][k].city][f])
					{
						printf("Gee");
						return 0;
					}
				}
			}
		}
	}
	if (cost[f] == 1e18 * 9) printf("gg");
	else printf("%lld", -cost[f]);
	return 0;
}