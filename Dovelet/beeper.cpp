#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;

class beep {
public:
	int level;
	vector<int> path;
	int bound;
};
class cmp
{
public:
	bool operator()(beep x, beep y) { return (x.bound > y.bound); }
};


pair <int, int> data;
vector < pair<int, int> > v;
int mat[25][25];
int N, M;
int X, Y;
int n, bd = 2e9;

int bound(beep node)
{
	int length = 0;
	bool A[25] = { 0 };
	for (int i = 0; i < node.path.size() - 1; i++)
	{
		length += mat[node.path[i]][node.path[i + 1]];
		A[node.path[i+1]] = 1;
	}
	A[node.path[0]] = 1;
	int min = 2e9;
	int minp;
	for (int i = 0; i <= n; i++)
	{
		if (!A[i] && mat[node.path[node.path.size()-1]][i] < min)
		{
			min = mat[node.path[node.path.size()-1]][i];
			minp = i;
		}
	}
	//A[minp] = 1;
	length += min;
	for (int i = 0; i <= n; i++)
	{
		min = 2e9;
		if (!A[i])
		{
			A[i] = 1;
			A[node.path[0]] = 0;
			for (int j = 0; j <= n; j++)
			{
				if (j==0 || !A[j])
				{
					if (min > mat[i][j]) min = mat[i][j];
				}
			}
			A[i] = 0;
			length += min;
		}
	}
	return length;
}
int length(beep x)
{
	int len = 0;
	for (int i = 0; i < x.path.size()-1; i++)
	{
		len += mat[x.path[i]][x.path[i + 1]];
	}
	return len;
}
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &N,&M);
	scanf("%d %d", &X, &Y);
	v.push_back(make_pair(X, Y));
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		v.push_back(make_pair(t1, t2));
		for (int j = i-1; j >= 0; j--)
		{
			mat[i][j] = mat[j][i] = abs(v[i].first-v[j].first)+abs(v[i].second-v[j].second);
		}
	}
	beep U,V;
	priority_queue<beep, vector<beep>, cmp> q;
	V.level = 0;
	V.path.push_back(0);
	V.bound = bound(V);
	int minlength = 2e9;
	q.push(V);
	while (!q.empty())
	{
		beep now = q.top();
		q.pop();
		int chk[25] = { 0 };
		if (now.bound < minlength)
		{
			U.level = now.level + 1;
			for (int i = 0; i < now.path.size(); i++) chk[now.path[i]] = 1;
			for (int i = 1; i <= n; i++)
			{
				if (!chk[i])
				{
					U.path.clear();
					U.path.assign(now.path.begin(), now.path.end());
					U.path.push_back(i);
					if (U.level == n-1)
					{
						chk[i] = 1;
						for (int j = 0; j <= n; j++) if (chk[j] == 0) { U.path.push_back(j); break; }
						U.path.push_back(0);
						chk[i] = 0;
						int len = length(U);
						if (len < minlength) {
							minlength = len;
						}
					}
					else
					{
						U.bound = bound(U);
						if (U.bound < minlength) q.push(U);
					}
				}
			}
		}
	}
	if (minlength == 2000000000) minlength = 0;
	printf("The shortest path has length %d", minlength);

}
