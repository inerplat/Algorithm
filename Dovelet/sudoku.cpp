#include <cstdio>
#include <cstdlib>
#include <vector>
#include <memory.h>
using namespace std;
int arr[10][10];
vector <pair<int, int> > no_answer;
bool isTrue(pair<int, int> RC)
{
	int row = RC.first, col = RC.second;
	int rowcnt, colcnt;
	bool rowchk[10] = { 0 }, colchk[10] = { 0 }, boxchk[10] = {0};

	for (int i = 1; i <= 9; i++)
	{
		if ((arr[row][i] != 0 && rowchk[arr[row][i]]) || (arr[i][col] != 0 && colchk[arr[i][col]])) return 0;
		++rowchk[arr[row][i]];
		++colchk[arr[i][col]];
	}
	int row2 = ((row - 1) / 3) * 3 + 1;
	int col2 = ((col - 1) / 3) * 3 + 1;
	for (int i = row2; i < row2 + 3; i++) 
		for (int j = col2 ; j < col2 + 3; j++)
		{
			if (arr[i][j]!=0 && boxchk[arr[i][j]]) return 0;
			++boxchk[arr[i][j]];
		}
	return 1;
}

void back(int depth)
{
	if (depth == no_answer.size())
	{
		for (int i = 1; i <= 9; i++)
		{
			for (int j = 1; j <= 9; j++) printf("%d", arr[i][j]);
			printf("\n");
		}
		exit(0);
	}
	for (int i = 1; i <= 9; i++)
	{
		int tmp = arr[no_answer[depth].first][no_answer[depth].second];
		arr[no_answer[depth].first][no_answer[depth].second] = i;
		if (isTrue(no_answer[depth]))
		{
			back(depth + 1);
		}
		arr[no_answer[depth].first][no_answer[depth].second] = tmp;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	for (int i = 1; i <= 9; i++) 
		for (int j = 1; j <= 9; j++) {
			scanf("%1d", &arr[i][j]);
			if (arr[i][j] == 0) no_answer.push_back(make_pair(i, j));
		}
	back(0);

}
