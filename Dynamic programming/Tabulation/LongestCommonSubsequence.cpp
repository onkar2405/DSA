#include <iostream>
#include <map>
#include <string>
using namespace std;

int lcs(string s1, string s2, int m, int n)
{
  int table[m + 1][n + 1];

  for (int i = 0; i <= n; i++)
  {
    table[0][i] = 0;
  }
  for (int i = 0; i <= m; i++)
  {
    table[i][0] = 0;
  }

  for (int i = 1; i <= m; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (s1[i - 1] == s2[j - 1])
      {
        table[i][j] = 1 + table[i - 1][j - 1];
      }
      else
      {
        table[i][j] = max(table[i][j - 1], table[i - 1][j]);
      }
    }
  }

  return table[m][n];
}

int main()
{
  string s1 = "AXYZ";
  string s2 = "BAZ";
  cout << lcs(s1, s2, s1.size(), s2.size());

  return 0;
}