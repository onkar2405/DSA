#include <iostream>
using namespace std;

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

int main()
{
  string str = "AAAA";
  string pattern = "AA";

  findPatternNaive(str, pattern);

  return 0;
}