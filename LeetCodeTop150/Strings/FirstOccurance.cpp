#include <iostream>
#include <vector>
using namespace std;

int strStr(string haystack, string needle)
{
  int i = 0;
  int j = 0;

  while (i < haystack.length())
  {
    if (haystack[i] == needle[j])
    {
      j = 1;
      while (j < needle.length())
      {
        if (needle[j] != haystack[i + j])
        {
          j = 0;
          break;
        }
        j++;
      }

      if (j == needle.size())
      {
        return i;
      }
    }
    i++;
  }

  return -1;
}