
#include <iostream>
#include <vector>
using namespace std;
/**
 * Problem link: https://leetcode.com/problems/remove-element/?envType=study-plan-v2&envId=top-interview-150
 */
int removeElement(vector<int> &nums, int val)
{
  // [3,2,2,3] val=3
  int i = 0;
  int count = 0;
  while (i < nums.size() - count)
  {
    if (nums[i] == val)
    {
      nums[i] = nums[nums.size() - count - 1];
      count = count + 1;
    }
    else
    {
      i++;
    }
  }

  return nums.size() - count;
}

int main()
{
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;

  int count = removeElement(nums, val);
  cout << count << "\n";

  for (int i = 0; i < nums.size(); i++)
  {
    cout << " " << nums[i];
  }

  return 0;
}