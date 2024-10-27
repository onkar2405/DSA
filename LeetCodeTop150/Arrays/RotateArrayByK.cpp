
#include <iostream>
#include <vector>
using namespace std;
/**
 * Problem link: https://leetcode.com/problems/rotate-array/?envType=study-plan-v2&envId=top-interview-150
 */

void rotateArray(vector<int> &nums, int k)
{

  vector<int> rotated(nums.size());

  for (int i = 0; i < nums.size(); i++)
  {
    int currentPos = i + k > nums.size() - 1 ? (i + k) % nums.size() : i + k;
    rotated[currentPos] = nums[i];
  }

  nums = rotated;
}

int main()
{
  vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
  int k = 3;

  rotateArray(nums, k);

  for (int i = 0; i < nums.size(); i++)
  {
    cout << " " << nums[i];
  }

  return 0;
}