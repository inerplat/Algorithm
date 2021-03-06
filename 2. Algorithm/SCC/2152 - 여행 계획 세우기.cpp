#include <cstdio>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <memory.h>
using namespace std;

class dataset {
public:
	int in, out;
	int index;
};

vector <int> G[10010];
vector <int> RG[10010];
vector <int> comp[10010];
vector <int> comp2[10010];
char chk[10010];
int compdata[10010];
int cnt;
int mys, myt;
dataset _data[10010];

bool cmp(dataset x, dataset y) { return x.out > y.out; }

void dfs(int vertex)
{
	int i, j;
	chk[vertex] = 1;
	_data[vertex].in = ++cnt;
	for (i = 0; i < G[vertex].size(); i++) if (!chk[G[vertex][i]])	dfs(G[vertex][i]);
	_data[vertex].out = ++cnt;
}

void dfs2(int vertex)
{
	int i, j;
	comp[cnt].push_back(vertex);
	chk[vertex] = 1;
	compdata[vertex] = cnt;
	for (i = 0; i < RG[vertex].size(); i++) 
		if (!chk[RG[vertex][i]]) dfs2(RG[vertex][i]);
}
int maxsum;
int answerarr[10010];
int d[10010];
int dfs3(int vertex, int sum)
{
	int i;
	chk[vertex] = 1;
	answerarr[vertex] = answerarr[vertex] < sum ? sum : answerarr[vertex];
	for (i = 0; i < comp2[vertex].size(); i++) 
		if (!chk[comp2[vertex][i]] && sum + comp[comp2[vertex][i]].size() > answerarr[comp2[vertex][i]]) 
			dfs3(comp2[vertex][i], sum + comp[comp2[vertex][i]].size());
	chk[vertex] = 0;
}

int main()
{
	int n, m, s, t;
	int i, j;
	//freopen("input.txt", "r", stdin);
	scanf("%d %d %d %d", &n, &m, &s, &t);
	for (int tmp1, tmp2, i = 1; i <= m; i++)
	{
		scanf("%d %d", &tmp1, &tmp2);
		G[tmp1].push_back(tmp2);
		RG[tmp2].push_back(tmp1);
	}

	for (i = 1; i <= n; i++)
	{
		if (!chk[i]) dfs(i);
		_data[i].index = i;
	}
	memset(chk, 0, sizeof(char)*(n+1));
	sort(&_data[1], &_data[n + 1], cmp);
	cnt = 0;
	for (i = 1; i <= n; i++)
	{
		if (!chk[_data[i].index])
		{
			++cnt;
			dfs2(_data[i].index);
		}
	}
	for (i = 1; i <= cnt; i++)
	{
		for (j = 0; j < comp[i].size(); j++)
		{
			if (comp[i][j] == s) mys = i;
			if (comp[i][j] == t) myt = i;
		}
	}
	for (i = 1; i <= cnt; i++)
	{
		for (j = 0; j < comp[i].size(); j++)
		{
			for (int k = 0; k < G[comp[i][j]].size(); k++)
			{
				int no = 0;
				for (int l = 0; l < comp2[compdata[comp[i][j]]].size(); l++)
				{
					if (comp2[compdata[comp[i][j]]][l] == compdata[G[comp[i][j]][k]]) no = 1;
				}
				if (no) continue;
				if (compdata[comp[i][j]] != compdata[G[comp[i][j]][k]])
					comp2[compdata[comp[i][j]]].push_back(compdata[G[comp[i][j]][k]]);
			}
		}
	}
	memset(chk, 0, sizeof(char)*(n + 1));
	dfs3(mys, comp[mys].size());
	printf("%d", answerarr[myt]);
	return 0;
}