#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m;
int penalty;
vector <int> list[3010];
int cost[3010][3010];
int flow[3010][3010];
int chk[3010];
int main()
{
	int i, j;
	scanf("%d %d %d", &n, &m, &penalty);
	int src = n + m + 1;
	int sink = src + 1;
	cost[src][0] = penalty;
	list[src].push_back(0);
	list[0].push_back(src);
	for (i = 1; i <= n; i++)
	{
		int t;
		scanf("%d", &t);
		for (j = 1; j <= t; j++)
		{
			int data;
			scanf("%d", &data);
			int new_vertex = n + data;
			list[i].push_back(new_vertex);
			list[new_vertex].push_back(i);
			cost[i][new_vertex] = 1;
		}
		cost[src][i] = 1;
		list[src].push_back(i);
		list[i].push_back(src);
		cost[0][i] = penalty;
		list[0].push_back(i);
		list[i].push_back(0);
	}
	for (i = n + 1; i <= n + m; i++)
	{
		cost[i][sink] = 1;
		list[i].push_back(sink);
		list[sink].push_back(i);
	}
	int answer = 0;
	while (1)
	{
		queue <int> q;
		fill(&chk[0], &chk[n + m + 3], -1);
		q.push(src);
		while (!q.empty())
		{
			int current = q.front();
			q.pop();
			for (int i: list[current])
			{
				if (cost[current][i] - flow[current][i] > 0 && chk[i] == -1)
				{
					q.push(i);
					chk[i] = current;
					if (i == sink) break;
				}
			}

		}
		if (chk[sink] == -1) break;	

		int nowflow = 1e9 * 2;
		for (i = sink; i != src; i = chk[i])
		{
			nowflow = nowflow < cost[chk[i]][i] - flow[chk[i]][i] ? nowflow : cost[chk[i]][i] - flow[chk[i]][i];
		}
		for (i = sink; i != src; i = chk[i])
		{
			flow[chk[i]][i] += nowflow;
			flow[i][chk[i]] -= nowflow;
		}
		answer += nowflow;
	}
	printf("%d", answer);
}