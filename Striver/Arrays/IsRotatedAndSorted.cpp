/**
 * https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/submissions/1488974104/
 */

#include <iostream>
#include <vector>
using namespace std;

bool check(vector<int> &nums)
{

  int violations = 0;

  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i - 1] > nums[i])
    {
      violations++;
    }
  }

  if (nums[0] < nums[nums.size() - 1])
  {
    violations++;
  }

  return violations <= 1;
}