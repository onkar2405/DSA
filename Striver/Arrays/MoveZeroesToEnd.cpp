#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/move-zeroes/
 */
void moveZeroes(vector<int> &nums)
{
  int zeroIndex = -1;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] != 0 && zeroIndex != -1)
    {
      nums[zeroIndex] = nums[i];
      nums[i] = 0;
      zeroIndex++;
    }
    if (nums[i] == 0 && zeroIndex == -1)
    {
      zeroIndex = i;
    }
  }
}