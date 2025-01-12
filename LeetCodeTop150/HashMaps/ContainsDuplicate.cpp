#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

bool containsNearbyDuplicate(vector<int> &nums, int k)
{
  if (nums.size() < 2)
  {
    return false;
  }

  unordered_map<int, int> umap;

  for (int i = 0; i < nums.size(); i++)
  {
    if (umap.find(nums[i]) != umap.end() && abs(umap[nums[i]] - i) <= k)
    {
      return true;
    }
    else
    {
      umap[nums[i]] = i;
    }
  }

  return false;
}