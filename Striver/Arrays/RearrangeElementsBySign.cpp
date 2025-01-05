#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/rearrange-array-elements-by-sign/
 */
vector<int> rearrangeArray(vector<int> &nums)
{
  int posInd = 0;
  int negInd = 1;

  vector<int> res(nums.size());

  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] > 0)
    {
      res[posInd] = nums[i];
      posInd += 2;
    }
    else
    {
      res[negInd] = nums[i];
      negInd += 2;
    }
  }

  return res;
}