#include <cstdio>
#include <cstdlib>
using namespace std;

class dataset {
public :
	int x, y;
	dataset(int xx, int yy) : x(xx), y(yy) {}
};

int pink_answer, white_answer;
int arr[222][222];


void back(int r, int c, int size)
{
	int cnt = 0;
	for (int i = r; i < r + size; i++) for (int j = c; j < c + size; j++) if (arr[i][j]) ++cnt;
	if (cnt == 0)
	{
		++white_answer;
		return;
	}
	else if (cnt == size*size)
	{
		++pink_answer;
		return;
	}
	int half_size = size / 2;
	back(r, c, half_size);
	back(r + half_size, c, half_size);
	back(r, c + half_size, half_size);
	back(r + half_size, c + half_size, half_size);

}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
	back(1,1,n);
	printf("%d\n%d", white_answer,pink_answer);
}
