#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/?envType=study-plan-v2&envId=top-interview-150
 */
int removeDuplicates(vector<int> &nums)
{
  int count = 1;
  vector<int> temp;
  temp.push_back(nums[0]);

  for (int i = 1; i < nums.size(); i++)
  {
    count = nums[i] == nums[i - 1] ? count + 1 : 1;

    if (count <= 2)
    {
      temp.push_back(nums[i]);
    }
  }
  nums = temp;
  return temp.size();
}

int removeDuplicatesOptimized(vector<int> &nums)
{
  int indexToUpdate = 2;
  if (nums.size() <= 2)
  {
    return nums.size();
  }

  for (int i = 2; i < nums.size(); i++)
  {
    if (nums[i] != nums[indexToUpdate - 2])
    {
      nums[indexToUpdate] = nums[i];
      indexToUpdate++;
    }
  }

  return indexToUpdate;
}

int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};

  int count = removeDuplicates(nums);

  for (int i = 0; i < nums.size(); i++)
  {
    cout << " " << nums[i];
  }

  return 0;
}