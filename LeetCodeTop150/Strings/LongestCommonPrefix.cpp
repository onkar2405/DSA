#include <iostream>
#include <vector>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
  if (strs.size() == 0)
  {
    return "";
  }

  if (strs.size() == 1)
  {
    return strs[0];
  }

  string str1 = strs[0];
  string str2 = strs[1];

  string prefix = "";

  int len = str1.length() > str2.length() ? str2.length() : str1.length();

  int i = 0;

  while (i < len)
  {
    if (str1[i] != str2[i])
    {
      break;
    }
    prefix += str1[i];
    i++;
  }

  for (i = 2; i < strs.size(); i++)
  {
    string currPrefix = "";
    int j = 0;
    int len = prefix.length() > strs[i].length() ? strs[i].length() : prefix.length();

    while (j < len)
    {
      if (prefix[j] != strs[i][j])
      {
        break;
      }

      currPrefix += prefix[j];
      j++;
    }

    if (currPrefix.length() < prefix.length())
    {
      prefix = currPrefix;
    }
  }

  return prefix;
}