#include <iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int *arr = (int *)calloc(n+1,sizeof(int));
	arr[n] = 1;
	for (int i = n; i >= 1; i--)
	{
		if (!(i % 3) && ((arr[i / 3] == 0) || (arr[i / 3] > arr[i] + 1))) arr[i / 3] = arr[i] + 1;
		if (!(i % 2) && ((arr[i / 2] == 0) || (arr[i / 2] > arr[i] + 1))) arr[i / 2] = arr[i] + 1;
		if (arr[i-1] == 0 || arr[i-1] > arr[i] + 1) arr[i-1] = arr[i] + 1;
	}
	cout << arr[1] - 1;
	free(arr);
	return 0;
}