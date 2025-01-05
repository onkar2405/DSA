
#include <iostream>
#include <vector>
#include <unordered_map>
#include <math.h>
using namespace std;

/**
 * https://leetcode.com/problems/sort-colors/
 */
void sortColors(vector<int> &nums)
{
  unordered_map<int, int> umap;

  for (int i = 0; i < nums.size(); i++)
  {
    umap[nums[i]]++;
  }

  int index = 0;

  for (int i = 0; i < 3; i++)
  {
    int j = 0;
    while (j < umap[i])
    {
      nums[index] = i;
      index++;
      j++;
    }
  }
}

void sortColorsThreePointers(vector<int> &nums)
{
  int r = 0;
  int b = nums.size() - 1;
  int w = 0;
  while (w <= b)
  {
    if (nums[w] == 2)
    {
      swap(nums[w], nums[b]);
      b--;
    }
    else if (nums[w] == 0)
    {
      swap(nums[w], nums[r]);
      r++;
      w++;
    }
    else
    {
      w++;
    }
  }
}