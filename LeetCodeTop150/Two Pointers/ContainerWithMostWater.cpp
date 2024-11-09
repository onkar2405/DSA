#include <iostream>
#include <vector>
using namespace std;

/**
 * https://leetcode.com/problems/container-with-most-water/?envType=study-plan-v2&envId=top-interview-150
 */
int maxArea(vector<int> &height)
{
  int maxArea = 0;
  int start = 0;
  int end = height.size() - 1;

  while (start <= end)
  {
    int tempArea = (end - start) * min(height[start], height[end]);
    maxArea = tempArea > maxArea ? tempArea : maxArea;

    if (height[start] > height[end])
    {
      end--;
    }
    else
    {
      start++;
    }
  }

  return maxArea;
}

int main()
{
  vector<int> inp = {2, 7, 11, 15};
  cout << maxArea(inp);
  return 0;
}