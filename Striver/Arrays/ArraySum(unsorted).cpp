#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

/**
 * https://leetcode.com/problems/subarray-sum-equals-k/submissions/1492708449/
 */

int subarraySum(vector<int> &nums, int k)
{
  unordered_map<int, int> umap;
  int maxLength = 0;
  int sum = 0;

  for (int i = 0; i < nums.size(); i++)
  {
    sum += nums[i];

    if (sum == k)
    {
      maxLength = i + 1;
    }

    if (umap.find(sum - k) != umap.end())
    {
      maxLength = max(maxLength, i - umap[sum - k]);
    }

    if (umap.find(sum - k) != umap.end())
    {
      umap[sum] = i;
    }
  }

  return maxLength;
}