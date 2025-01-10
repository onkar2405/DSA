#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/word-pattern/
 */
bool wordPattern(string pattern, string s)
{
  unordered_map<char, string> umap;

  vector<string> v;
  int i = 0;
  string str;
  while (i != s.length())
  {
    if (s[i] == ' ')
    {
      v.push_back(str);
      str.clear();
      i++;
      continue;
    }
    str += s[i];
    i++;
  }
  v.push_back(str);

  if (v.size() != pattern.size())
  {
    return false;
  }

  i = 0;
  unordered_set<string> seenWords;

  while (i < pattern.size())
  {
    if (umap.find(pattern[i]) == umap.end())
    {
      if (seenWords.find(v[i]) != seenWords.end())
      {
        return false;
      }
      umap[pattern[i]] = v[i];
      seenWords.insert(v[i]);
    }
    else
    {
      if (umap[pattern[i]] != v[i])
      {
        return false;
      }
    }
    i++;
  }

  return true;
}