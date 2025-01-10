#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
  if (s.length() != t.length())
  {
    return false;
  }

  unordered_map<char, int> umapS;

  int i = 0;
  while (i < s.length())
  {
    umapS[s[i]]++;
    i++;
  }

  i = 0;

  while (i < t.size())
  {
    if (umapS.find(t[i]) == umapS.end() || umapS[t[i]] == 0)
    {
      return false;
    }
    umapS[t[i]]--;
    i++;
  }

  return true;
}