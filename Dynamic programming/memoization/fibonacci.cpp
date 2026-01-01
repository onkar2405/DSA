#include <iostream>
#include <vector>
using namespace std;

int fiboTabulization(int n)
{
  vector<int> memo(n + 1, -1);

  memo[0] = 0;
  memo[1] = 1;

  for (int i = 2; i <= n; i++)
  {
    memo[i] = memo[i - 1] + memo[i - 2];
  }

  return memo[n];
}

int fibo(int n, vector<int> &memo)
{
  // 0 1 1 2 3 5 8 13 21..

  if (memo[n] == -1)
  {
    int res;

    if (n == 1 || n == 0)
    {
      res = n;
    }
    else
    {
      res = fibo(n - 1, memo) + fibo(n - 2, memo);
    }
    memo[n] = res;
  }

  return memo[n];
}

int main()
{
  int n = 10;
  vector<int> memo(n + 1, -1);

  cout << fibo(n, memo) << "\n";
  cout << fiboTabulization(n) << "\n";

  return 0;
}