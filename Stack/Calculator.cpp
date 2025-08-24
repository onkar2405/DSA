#include <iostream>
#include <stack>
#include <math.h>
using namespace std;

int calculate(string s)
{
  stack<pair<int, int>> stack;
  int sign = 1;
  long long sum = 0;

  for (int i = 0; i < s.size(); i++)
  {
    if (isdigit(s[i]))
    {
      long long num = 0;
      while (i < s.size() && isdigit(s[i]))
      {
        num = num * 10 + (s[i] - '0');
        i++;
      }
      sum = sum + sign * num;
      sign = 1;
      i--;
    }
    else if (s[i] == '-')
    {
      sign = -1 * sign;
    }
    else if (s[i] == '(')
    {
      stack.push({sign, sum});
      sign = 1;
      sum = 0;
    }
    else if (s[i] == ')')
    {
      sum = sum * stack.top().first + stack.top().second;
      stack.pop();
      sign = 1;
    }
  }

  return sum;
}

int main()
{
  cout << calculate(" 2-1 +2");

  return 0;
}