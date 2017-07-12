#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int Answer;
char str[1000010];
int answer[1000010];
stack <char> s;
int main(int argc, char** argv)
{
   int T, test_case;

//   freopen("input.txt", "r", stdin);

   scanf("%d", &T);
   for (test_case = 0; test_case < T; test_case++)
   {
      Answer = 0;
      int tmp = 0;
      scanf("%s", &str[1]);
      int n = strlen(&str[1]);
      while (!s.empty()) s.pop();
      for (int i = 0; i <= n; i++) answer[i] = 0;
      for (int i = 1; i <= n; i++)
      {
         if (str[i] == '(' || str[i] == '{' || str[i] == '[') s.push(str[i]);
         else if (!s.empty() && ((str[i] == ')' && s.top() == '(') || (str[i] == '}' && s.top() == '{') || (str[i] == ']' && s.top() == '[')))
         {
            tmp = answer[s.size()];
            answer[s.size()] = 0;
            s.pop();
            answer[s.size()] += 2 + tmp;
         }
         else s.push(str[i]);
      }
      for (int i = 0; i <= n; i++) if (Answer < answer[i]) Answer = answer[i];
      cout << "Case #" << test_case + 1 << endl;
      cout << Answer << endl;
   }

   return 0;
}