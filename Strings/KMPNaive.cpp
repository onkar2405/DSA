#include <iostream>
using namespace std;

int kmpNaive(string str, int n)
{
  for (int len = n - 1; len > 0; len--)
  {
    bool flag = true;

    for (int i = 0; i < len; i++)
    {
      if (str[i] != str[n - len + i])
      {
        flag = false;
      }
    }

    if (flag == true)
    {
      return len;
    }
  }
  return 0;
}

int main()
{
  // LPS: Longest PROPER prefix suffix
  string str = "abacabad";
  int lps[str.length()];

  for (int i = 0; i < str.length(); i++)
  {
    lps[i] = kmpNaive(str, i + 1);
  }

  for (int i = 0; i < str.length(); i++)
  {
    cout << lps[i] << " ";
  }
  return 0;
}
