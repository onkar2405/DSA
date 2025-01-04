
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

/**
 * https://leetcode.com/problems/two-sum/
 */
vector<int> twoSumTwoIterations(vector<int> &nums, int target)
{
  unordered_map<int, int> umap;
  vector<int> res;

  for (int i = 0; i < nums.size(); i++)
  {
    umap[nums[i]] = i;
  }

  for (int i = 0; i < nums.size(); i++)
  {
    if (umap.find(target - nums[i]) != umap.end() && i != umap[target - nums[i]])
    {
      res.push_back(i);
      res.push_back(umap[target - nums[i]]);
      break;
    }
  }
  return res;
}

vector<int> twoSumSingleIteration(vector<int> &nums, int target)
{
  unordered_map<int, int> umap;
  vector<int> res;

  for (int i = 0; i < nums.size(); i++)
  {
    int complement = target - nums[i];

    if (umap.find(complement) != umap.end() && umap[complement] != i)
    {
      res.push_back(i);
      res.push_back(umap[complement]);

      return res;
    }

    umap[nums[i]] = i;
  }

  return res;
}