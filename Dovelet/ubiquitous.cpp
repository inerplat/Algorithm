#include <cstdio>
#include <cstdlib>
using namespace std;

int dataset[50005];
bool chk[50005];
int find(int x)
{
	if (x == dataset[x]) return x;
	return dataset[x]=find(dataset[x]);
}

void myunion(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	dataset[x] = y;
}
int main()
{
	freopen("input.txt", "r", stdin);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) dataset[i] = i;

	for (int i = 1; i <= m; i++)
	{
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		myunion(t1, t2); 
	}
	for (int i = 1; i <= n; i++) find(i);
	int cnt = 0;

	for (int i = 1; i <= n; i++) chk[dataset[i]] = 1;
	for (int i = 1; i <= n; i++) if(chk[i]) ++cnt;
	printf("%d", cnt);
	return 0;
}
