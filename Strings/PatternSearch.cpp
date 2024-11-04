#include <iostream>
using namespace std;

/**
 * This function works for all types of patterns i.e. distinct and non-distinct.
 */
void findPatternNaive(string str, string pattern)
{
  for (int i = 0; i <= str.length() - pattern.length(); i++)
  {
    if (pattern[0] == str[i])
    {
      int j = 1;
      while (j < pattern.length())
      {
        if (pattern[j] != str[i + j])
        {
          break;
        }
        j++;
      }
      if (j == pattern.length())
      {
        cout << i << " ";
      }
    }
  }
}

/**
 * This function works only for distinct types of patterns i.e. ABCD.
 */
void findPatternImprovedNaiveOnlyDistinct(string str, string pattern)
{
  int m = str.length();
  int n = pattern.length();

  for (int i = 0; i <= m - n; i++)
  {
    if (pattern[0] == str[i])
    {
      int j = 1;
      while (j < n)
      {
        if (pattern[j] != str[i + j])
        {
          i = i + j - 1;
          break;
        }
        j++;
      }

      if (j == n)
      {
        cout << i << " ";
      }
    }
  }
}

int main()
{
  string str = "ABCABCDDABCD";
  string pattern = "ABCD";

  findPatternNaive(str, pattern);
  findPatternImprovedNaiveOnlyDistinct(str, pattern);

  return 0;
}