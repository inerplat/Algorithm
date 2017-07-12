#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int Answer;
int n, m;
class point {
public:
	int p;
	int stat;
	point() {}
	point(int xx, int ssss) : p(xx), stat(ssss) {}
};
class coord {
public:
	int stat;
	int r, c;
};
vector<point> arr[22222];
int chk[22222];
coord light[110][110];
queue <int> q;
int main(int argc, char** argv)
{
	int T, test_case;
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for (test_case = 0; test_case < T; test_case++)
	{
		int i, j;
		scanf("%d %d", &n, &m);
		for (i = 0; i <= n*m * 2; i++)
		{
			arr[i].clear();
			chk[i] = 0;
		}
		while (!q.empty()) q.pop();
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				int tmp1, tmp2;
				scanf("%d %d %d", &light[i][j].stat, &light[i][j].r, &light[i][j].c);
				if (!light[i][j].stat) light[i][j].stat = -1;
				arr[i*m + light[i][j].r].push_back(point(n*m + j*n + light[i][j].c, light[i][j].stat));
				arr[n*m + j*n + light[i][j].c].push_back(point(i*m + light[i][j].r, light[i][j].stat));
			}
		}
		cout << "Case #" << test_case + 1 << endl;
		int end = 0;
		for (i = 0; i < n*m; i++)
		{
			if (!chk[i])
			{
				q.push(i);
				chk[i] = 1;
			}
			while (!q.empty())
			{
				int now = q.front();
				q.pop();
				for (j = 0; j < arr[now].size(); j++)
				{
					if (arr[now][j].stat == 1)
					{
						if (!chk[arr[now][j].p])
						{
							chk[arr[now][j].p] = chk[now];
							q.push(arr[now][j].p);
						}
						else if (chk[arr[now][j].p] != chk[now])
						{
							printf("Impossible");
							end = 1;
							break;
						}

					}
					else
					{
						if (!chk[arr[now][j].p])
						{
							chk[arr[now][j].p] = -chk[now];
							q.push(arr[now][j].p);
						}
						else if (chk[arr[now][j].p] != -chk[now])
						{
							printf("Impossible");
							end = 1;
							break;
						}
					}
				}
				if (end == 1) break;
			}
			if (end == 1) break;
		}

		if (end == 0)
		{
			for (i = 0; i < n*m; i++)
			{
				if (chk[i] == -1)
				{
					printf("R%02d%02d ", i / m, i%m);
				}
			}
			for (i = n*m; i < 2 * n*m; i++)
			{
				if (chk[i] == -1)
				{
					printf("C%02d%02d ", (i - n*m) / n, (i - n*m) % n);
				}
			}
		}
		cout << endl;
	}
	return 0;
}