#include <cstdio>
#include <cstdlib>
using namespace std;
int a[2555];
int chk[333], answer[55];
int n, i;
void back(int p, int num, int cnt)
{
	if (n==cnt-1)
	{
		for (int j = 1; j < cnt; j++) printf("%d ", answer[j]);
		exit(0);
	}
	num = num * 10 + a[p];
	if (num > n) return;
	if (!chk[num])
	{
		answer[cnt] = num;
		chk[num] = 1;
		back(p + 1, 0, cnt + 1);
		chk[num] = 0;
	}
	if(p+1!=i) back(p + 1, num, cnt);
}
int main()
{
	//freopen("input.txt", "r", stdin);
	while (scanf("%1d", &a[++i]) != EOF);
	n = i-1 < 10 ? i-1 : 9 + (i - 10) / 2;
	back(0, 0, 0);
}