#include <iostream>
using namespace std;

/**
 * Consideration here: Given array is sorted.
 */
bool findSum(int *arr, int requiredSum, int len)
{
  int start = 0;
  int end = len - 1;

  while (start <= end)
  {
    int sum = arr[start] + arr[end];

    if (sum == requiredSum)
    {
      return true;
    }
    if (sum < requiredSum)
    {
      start = start + 1;
    }
    else
    {
      end = end - 1;
    }
  }
  return false;
}

int main()
{
  int arr[] = {2, 4, 6, 8, 11, 12, 16, 20};
  int sum = 25;

  cout << findSum(arr, sum, 8);
  return 0;
}