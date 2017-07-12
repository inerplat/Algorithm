#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
class input {
public:
	int x, y;
	double data;
};
input newdata[1000010];
input in[1010];
int chk[1010];
double answer = 0;
bool cmp(input x, input y) { return x.data < y.data; }
class unfind {
public:
	int parent, size;
	double answer;
};
unfind uf[1010];
void init(int n)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		uf[i].parent = i;
		uf[i].size = 1;
	}
}
int find(int p)
{
	if (uf[p].parent == p) return p;
	else return uf[p].parent = find(uf[p].parent);
}
void uni(int p, int q, double cost)
{
	p = find(p);
	q = find(q);
	uf[p].parent = q;
	uf[q].size += uf[p].size;
	uf[q].answer += uf[p].answer + cost;
}
int main()
{
	int n, m, cnt = 0;
	int i, j;
	//freopen("input.txt", "r", stdin);
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d", &in[i].x, &in[i].y);
		for (j = 1; j <= i - 1; j++)
		{
			double tmp = sqrt(pow(in[i].x - in[j].x, 2) + pow(in[i].y - in[j].y, 2));
			newdata[++cnt].x = i;
			newdata[cnt].y = j;
			newdata[cnt].data = tmp;
		}
	}
	for (i = 1; i <= m; i++)
	{
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		newdata[++cnt].x = tmp1;
		newdata[cnt].y = tmp2;
		newdata[cnt].data = 0;
	}
	sort(&newdata[1], &newdata[cnt + 1], cmp);
	init(n);
	for (i = 1; i <= cnt; i++)
	{
		if (find(newdata[i].x) != find(newdata[i].y)) 
			uni(newdata[i].x, newdata[i].y, newdata[i].data);
	}
	double max = 0;
	for (i = 1; i <= n; i++) if (uf[i].answer > max) max = uf[i].answer;
	printf("%.2lf", max);
	return 0;
}