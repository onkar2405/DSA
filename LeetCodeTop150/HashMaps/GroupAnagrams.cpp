#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
  unordered_map<string, vector<string>> umap;

  for (int i = 0; i < strs.size(); i++)
  {
    string str = strs[i];
    sort(str.begin(), str.end());
    umap[str].push_back(strs[i]);
  }

  vector<vector<string>> res;

  auto itr = umap.begin();
  while (itr != umap.end())
  {
    res.push_back(itr->second);
    itr++;
  }

  return res;
}