#include <iostream>
#include <map>
#include <string>
using namespace std;

int lcs(string s1, string s2, int m, int n, map<pair<string, string>, int> &memo)
{
  if (m == 0 || n == 0)
  {
    return 0;
  }

  if (s1[m - 1] == s2[n - 1])
  {
    return 1 + lcs(s1, s2, m - 1, n - 1, memo);
  }
  pair<string, string> inputPair = make_pair(s1, s2);

  if (memo.find(inputPair) != memo.end())
  {
    return memo[inputPair];
  }

  string subS1 = s1.substr(0, m - 1);
  string subS2 = s2.substr(0, n - 1);

  int res1 = lcs(s1, s2, m - 1, n, memo);
  int res2 = lcs(s1, s2, m, n - 1, memo);
  memo[make_pair(s1, subS2)] = res2;
  memo[make_pair(subS1, s2)] = res1;

  return max(res1, res2);
}

int lcs(string s1, string s2, int m, int n)
{
  if (m == 0 || n == 0)
  {
    return 0;
  }

  if (s1[m - 1] == s2[n - 1])
  {
    return 1 + lcs(s1, s2, m - 1, n - 1);
  }

  return max(lcs(s1, s2, m - 1, n), lcs(s1, s2, m, n - 1));
}

int main()
{
  string s1 = "AXY";
  string s2 = "ARY";

  map<pair<string, string>, int> memo;

  cout << lcs(s1, s2, s1.size(), s2.size(), memo);

  return 0;
}