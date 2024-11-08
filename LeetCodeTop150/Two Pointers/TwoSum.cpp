
#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
 */
vector<int> twoSum(vector<int> &numbers, int target)
{
  vector<int> twoNums;

  int start = 0;
  int end = numbers.size() - 1;
  // 2 7 11 15
  while (start <= end)
  {
    int tempSum = numbers[start] + numbers[end];
    if (tempSum == target)
    {
      twoNums.push_back(start + 1);
      twoNums.push_back(end + 1);
      return twoNums;
    }

    if (tempSum > target)
    {
      end--;
    }
    else
    {
      start++;
    }
  }
  return twoNums;
}

int main()
{
  vector<int> inp = {2, 7, 11, 15};

  vector<int> output = twoSum(inp, 18);

  for (int i = 0; i < output.size(); i++)
  {
    cout << output[i] << " ";
  }

  return 0;
}