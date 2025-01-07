#include <iostream>
#include <unordered_map>
using namespace std;

bool isIsomorphic(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }

  unordered_map<char, char> sMap;
  unordered_map<char, bool> isUsed;

  for (int i = 0; i < s.length(); i++)
  {
    if (sMap.find(s[i]) == sMap.end() && !isUsed[t[i]])
    {
      sMap[s[i]] = t[i];
      isUsed[t[i]] = true;
    }
    else
    {
      if (sMap[s[i]] != t[i])
      {
        return false;
      }
    }
  }

  return true;
}