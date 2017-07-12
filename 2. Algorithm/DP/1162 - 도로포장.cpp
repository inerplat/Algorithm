#include <cstdio>
#include <functional>
#include <vector>
#include <queue>
using namespace std;
class doro {
public:
	int road;
	long long cost;
	doro(int x, int y) : road(x), cost(y) {}
	bool operator>(const doro x) const
	{
		return this->cost>x.cost;
	}
	bool operator<(const doro x) const
	{
		return this->cost<x.cost;
	}
};

class cmp {
public:
	bool operator()(pair<doro,int> x, pair<doro, int> y )
	{
		return x.first.cost > y.first.cost;
	}
};

priority_queue < pair<doro,int> ,vector< pair<doro,int> >, cmp> q;
vector <doro> v[10010];
long long d[22][10010];
bool visited[10010];
int main()
{
	int i, j;
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 1; i <= m; i++)
	{
		int tmp1, tmp2, tmp3;
		scanf("%d %d %d", &tmp1, &tmp2, &tmp3);
		v[tmp1].push_back(doro(tmp2, tmp3));
		v[tmp2].push_back(doro(tmp1, tmp3));
	}
	for (i = 0; i <= k; i++) for (j = 2; j <= n; j++) d[i][j] = 1e9 * 2;
	q.push(make_pair(doro(1, 0),0));
	while (!q.empty())
	{
		int now_road = q.top().first.road;
		long long now_cost = q.top().first.cost;
		int now_level = q.top().second;
		q.pop();
		for (i = 0; i < v[now_road].size(); i++)
		{
			int next_road = v[now_road][i].road;
			long long next_cost = v[now_road][i].cost + now_cost;
			if (d[now_level + 1][next_road] > now_cost)
			{
				q.push(make_pair( doro(next_road, now_cost), now_level + 1) );
				d[now_level + 1][next_road] = now_cost;
			}
			if (d[now_level][next_road] > next_cost)
			{
				q.push(make_pair( doro(next_road, next_cost), now_level) );
				d[now_level][next_road] = next_cost;
			}
		}
	}
	int minp = 0;
	for (i = 1; i <= k; i++) if (d[i][n] < d[minp][n]) minp = i;
	printf("%lld", d[minp][n]);
	return 0;
}
