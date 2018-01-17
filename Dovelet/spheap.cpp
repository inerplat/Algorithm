#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class dataset {
public:
	pair<int, int> point;
	int cost;
	dataset(int x, int y, int z) : point(make_pair(x,y)), cost(z) {}

};
class cmp{
public:
	bool operator()(dataset xx, dataset yy)
	{
		return xx.cost > yy.cost;
	}
};
vector<dataset> v[201][201];


int map[201][201];
int dist[201][201];
int main()
{
	int n, m;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) scanf("%d", &map[i][j]);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (i - 1 > 0) v[i][j].push_back(dataset(i - 1, j, map[i - 1][j]));
			if (j - 1 > 0) v[i][j].push_back(dataset(i, j - 1, map[i][j - 1]));
			if (i + 1 <= n) v[i][j].push_back(dataset(i + 1, j, map[i + 1][j]));
			if (j + 1 <= m) v[i][j].push_back(dataset(i, j + 1, map[i][j + 1]));
		}
	}
	pair<int, int> src, sink;
	scanf("%d %d %d %d", &src.first, &src.second, &sink.first, &sink.second);
	priority_queue<dataset, vector<dataset>, cmp> q;
	q.push(dataset(src.first, src.second, map[src.first][src.second]));
	fill(&dist[0][0], &dist[200][201], 1e9);
	dist[src.first][src.second] = map[src.first][src.second];
	while (!q.empty())
	{
		pair<int, int> now = q.top().point;
		int now_cost = q.top().cost;
		q.pop();
		//for(auto vt : v[now.first][now.second])
		for (int i=0;i<v[now.first][now.second].size();i++)
		{
			dataset vt = v[now.first][now.second][i];
			int next_cost = now_cost + vt.cost;
			if (dist[vt.point.first][vt.point.second] > next_cost)
			{
				dist[vt.point.first][vt.point.second] = next_cost;
				q.push(dataset(vt.point.first, vt.point.second, next_cost));
			}
		}
	}
	printf("%d", dist[sink.first][sink.second]);
	return 0;

}
