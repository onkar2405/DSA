#include <iostream>
#include <unordered_set>
using namespace std;
/**
 * In this particular problem, we are presented with an array of integers, and our objective is to find if a subarray with sum equal to 0 exists in the array
 */
bool checkSubArrayWithZeroSum(int *arr, int len)
{
  unordered_set<int> sum;
  int prefixSum = 0;
  for (int i = 0; i < len; i++)
  {
    prefixSum += arr[i];
    if (prefixSum == 0)
    {
      return 1;
    }
    // Logic: if prefixSum already exist in set mean, there is a sub-array with sum 0.
    if (sum.find(prefixSum) == sum.end())
    {
      sum.insert(prefixSum);
    }
    else
    {
      return 1;
    }
  }
  return 0;
}

bool checkSubArrayWithGivenSum(int *arr, int len, int requiredSum)
{
  unordered_set<int> sum;
  int prefixSum = 0;
  for (int i = 0; i < len; i++)
  {
    prefixSum += arr[i];
    // This condition is required to solve arr2 edge case
    if (prefixSum == requiredSum)
    {
      return 1;
    }
    // Logic: if prefixSum already exist in set mean, there is a sub-array with sum 0.
    if (sum.find(prefixSum - requiredSum) == sum.end())
    {
      sum.insert(prefixSum);
    }
    else
    {
      return 1;
    }
  }
  return 0;
}

int main()
{

  int arr[] = {1, 3, 4, -2, 5, 8};
  int arr1[] = {2, 3, 4, 6};

  cout << checkSubArrayWithZeroSum(arr, 6) << "\n";
  cout << checkSubArrayWithGivenSum(arr1, 4, 9);

  return 0;
}