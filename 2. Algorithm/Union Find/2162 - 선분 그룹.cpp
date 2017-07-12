#include <cstdio>
class point
{
public:
	int x1, x2, y1, y2;
};
point input[3333];
int par[3333];
int chk[3333];
void init(int n) { for (int i = 1; i <= n; i++) par[i] = i; }
int find(int p)
{
	if (par[p] == p) return p;
	else return par[p] = find(par[p]);
}
void uni(int p, int q)
{
	p = find(p);
	q = find(q);
	if (p == q) return;
	par[p] = q;
}
inline int CCW(int x1, int y1, int x2, int y2, int x3, int y3)
{
	int tmp = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
	return tmp>0 ? 1 : tmp<0 ? -1 : 0;
}
int main()
{
	int n;
	double result;
	int i, j, cnt = 0, max = 0;
	scanf("%d", &n);
	init(n);
	for (i = 1; i <= n; i++)
	{
		scanf("%d %d %d %d", &input[i].x1, &input[i].y1, &input[i].x2, &input[i].y2);
		if (input[i].x1 > input[i].x2)
		{
			int tmp = input[i].x1; input[i].x1 = input[i].x2; input[i].x2 = tmp;
			tmp = input[i].y1; input[i].y1 = input[i].y2; input[i].y2 = tmp;
		}
		if (input[i].x1 == input[i].x2 && input[i].y2 < input[i].y1)
		{
			int tmp = input[i].x1; input[i].x1 = input[i].x2; input[i].x2 = tmp;
			tmp = input[i].y1; input[i].y1 = input[i].y2; input[i].y2 = tmp;
		}
		for (j = 1; j <= i - 1; j++)
		{
			int result1 = CCW(input[i].x1, input[i].y1, input[i].x2, input[i].y2, input[j].x1, input[j].y1)*
				CCW(input[i].x1, input[i].y1, input[i].x2, input[i].y2, input[j].x2, input[j].y2);
			int result2 = CCW(input[j].x1, input[j].y1, input[j].x2, input[j].y2, input[i].x1, input[i].y1)*
				CCW(input[j].x1, input[j].y1, input[j].x2, input[j].y2, input[i].x2, input[i].y2);
			if ((result1 < 0 && result2<0) || (!result1 && result2<0) || (!result2 && result1<0)) uni(i, j);

			else if (!result1 && !result2)
			{
				if (input[i].x1 == input[i].x2)
				{
					if ((input[i].y1 <= input[j].y1 && input[j].y1 <= input[i].y2) ||
						(input[i].y1 <= input[j].y2 && input[j].y2 <= input[i].y2) ||
						(input[j].y1 <= input[i].y1 && input[i].y1 <= input[j].y2) ||
						(input[j].y1 <= input[i].y2 && input[i].y2 <= input[j].y2))
						uni(i, j);
				}
				else if ((input[i].x1 <= input[j].x1 && input[j].x1 <= input[i].x2) ||
					(input[i].x1 <= input[j].x2 && input[j].x2 <= input[i].x2) ||
					(input[j].x1 <= input[i].x1 && input[i].x1 <= input[j].x2) ||
					(input[j].x1 <= input[i].x2 && input[i].x2 <= input[j].x2))
					uni(i, j);
			}

		}
	}
	for (i = 1; i <= n; i++)
	{
		chk[find(i)]++;
	}
	for (i = 1; i <= n; i++) {
		if (chk[i] > max) max = chk[i];
		if (chk[i]) ++cnt;
	}
	printf("%d\n%d", cnt, max);
}