#include <iostream>
using namespace std;

int fibo(int n,int *cnt0, int *cnt1)
{	
	if (n == 0)
	{
		(*cnt0)++;
		return 0;
	}
	else if (n == 1)
	{
		(*cnt1)++;
		return n;
	}
	return fibo(n - 1,cnt0, cnt1) + fibo(n - 2, cnt0, cnt1);
}

int main()
{
	int n, m;
	int cnt0=0;
	int cnt1=0;
	cin >> n;
	for (int i=1; i <= n; i++)
	{
		cnt0 = cnt1 = 0;
		cin >> m;
		fibo(m, &cnt0, &cnt1);
		cout << cnt0 << ' ' << cnt1 << endl;
	}
	return 0;
}