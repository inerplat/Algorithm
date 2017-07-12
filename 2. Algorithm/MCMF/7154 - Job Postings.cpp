#include <cstdio>
#include <vector>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 2147483647

pair <int, int> trace[1010];
pair <int, int> answer;

class edge {
public:
	int vertex, cost, flow, reverse;
	edge(int vt, int ct, int fl, int rv) : vertex(vt), cost(ct), flow(fl),reverse(rv) {}
};
vector <edge> list[1010];
void push_data(int now, int next, int cost, int flow)
{
	list[now].push_back(edge(next, cost, flow,list[next].size()));
	list[next].push_back(edge(now, -cost, 0,list[now].size()-1));
}
int main()
{
	int n, m;
	int i, j;
	while (1)
	{
		scanf("%d %d", &n, &m);
		if (!n && !m) return 0;
		for (i = 0; i < 1010; i++) { list[i].clear(); trace[i].first = trace[i].second = -1; }
		answer.first = answer.second = 0;
		int src = n + m + 1;
		int sink = src + 1;
		for (i = 0; i < n; i++)
		{
			int flow;
			scanf("%d", &flow);
			push_data(src, i, 0, flow);
		}
		for (i = 0; i < m; i++)
		{
			int grade;
			scanf("%d", &grade);
			
			for (j = 0;j<=3;j++)
			{
				int work;
				scanf("%d", &work);
				push_data(work, n + i, -(grade*4-j), 1);
			}
			push_data(n + i, sink, 0, 1);
		}
		while (1)
		{
			queue <int> q;
			int chk[1010],cost[1010];
			fill(&chk[0], &chk[n + m + 3], 0);
			fill(&cost[0], &cost[n + m + 3], MAX);
			q.push(src);
			cost[src] = 0;
			chk[src] = 1;
			while (!q.empty())
			{
				int now = q.front();
				q.pop();
				chk[now] = 0;
				for (i = 0; i < list[now].size(); i++)
				{
					int next_vertex = list[now][i].vertex;
					int next_flow = list[now][i].flow;
					if (next_flow && cost[next_vertex] > cost[now] + list[now][i].cost)
					{
						cost[next_vertex] = cost[now] + list[now][i].cost;
						trace[next_vertex].first = now;
						trace[next_vertex].second = i;
						if (!chk[next_vertex])
						{
							chk[next_vertex] = 1;
							q.push(next_vertex);
						}
					}
				}
			}	
			if (cost[sink] == MAX) break;
			int nowflow = MAX;
			for (i = sink; i != src; i = trace[i].first)
			{
				nowflow = nowflow < list[trace[i].first][trace[i].second].flow ? nowflow : list[trace[i].first][trace[i].second].flow;
			}
			for (i = sink; i != src; i = trace[i].first)
			{
				list[trace[i].first][trace[i].second].flow -= nowflow;
				list[i][list[trace[i].first][trace[i].second].reverse].flow += nowflow;
				answer.first += list[trace[i].first][trace[i].second].cost*nowflow;
			}
			answer.second += nowflow;
		}
		printf("%d\n", -answer.first);
	}
}