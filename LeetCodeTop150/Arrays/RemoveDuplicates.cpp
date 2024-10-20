#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150
 */

int removeDuplicatesOptimal(vector<int> &nums)
{
  int positionToAddNextNonDuplicateElement = 1;
  for (int i = 1; i < nums.size(); i++)
  {
    if (nums[i] != nums[i - 1])
    {
      nums[positionToAddNextNonDuplicateElement] = nums[i];
      positionToAddNextNonDuplicateElement++;
    }
  }

  return positionToAddNextNonDuplicateElement;
}

int removeDuplicates(vector<int> &nums)
{
  vector<int> unique;
  if (nums.size() > 0)
  {
    unique.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
      if (nums[i] != unique.back())
      {
        unique.push_back(nums[i]);
      }
    }
  }

  nums = unique;

  return unique.size();
}

int main()
{
  vector<int> nums = {1, 2, 2, 3, 3, 4};

  int count = removeDuplicates(nums);
  cout << count << "\n";

  for (int i = 0; i < nums.size(); i++)
  {
    cout << " " << nums[i];
  }

  return 0;
}