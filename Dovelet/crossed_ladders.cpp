#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

inline double min(double x, double y) { return (x > y ? y : x); }

double x, y, c;
inline double answer(double a)
{
	return ((c / (sqrt(pow(y, 2) - pow(a, 2)))) + (c / (sqrt(pow(x, 2) - pow(a, 2)))) - 1);
}

long long back(double low, double high)
{
	double mid = (low + high) / 2;
	double ans = answer(mid);
	long long t1, t2;
	t1 = (low+0.0005) * 1000;
	t2 = (high + 0.0005) * 1000;

	if (t1==t2) return t1;
	else if (ans < 0) back(mid, high);
	else if (ans > 0) back(low, mid);
	
}

int main()
{
	scanf("%lf %lf %lf", &x, &y, &c);

	double ans;
	ans=back(0, min(x, y));
	printf("%.3lf", (double) (ans/1000));
	return 0;
}
