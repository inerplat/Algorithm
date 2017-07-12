#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

int Answer;
int arr[200010];
int main(int argc, char** argv)
{
   int T, test_case;


   // freopen("input.txt", "r", stdin);

   cin >> T;
   for (test_case = 0; test_case < T; test_case++)
   {

      Answer = 0;
      int n;
      int max = 0;
      scanf("%d", &n);
      fill(&arr[0], &arr[n + 1], 0);
      for (int i = 1; i <= n; i++)
      {
         scanf("%d", &arr[i]);
         if (max < arr[i]) max = arr[i];
      }
      arr[0] = max+1;
      for (int i = 1; i < n; i++)
      {
         if (arr[i - 1] - arr[i] > 0 && arr[i]-arr[i+1]<0) Answer++;
      }
      cout << "Case #" << test_case + 1 << endl;
      cout << Answer*2 << endl;
   }

   return 0;//Your program should return 0 on normal termination.
}