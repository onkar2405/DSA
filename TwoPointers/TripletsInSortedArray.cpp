#include <iostream>
using namespace std;

/**
 * Consideration here: Given array is sorted.
 *
 * I/P = [1,2,3,4] sum=9
 * O/P = true; {2+3+4= required sum 9}
 *
 */
bool isPair(int *arr, int requiredSum, int start, int len)
{
  int end = len - 1;

  while (start <= end)
  {
    int sum = arr[start] + arr[end];

    if (sum == requiredSum)
    {
      return true;
    }
    if (sum > requiredSum)
    {
      end = end - 1;
    }
    else
    {
      start = start + 1;
    }
  }
  return false;
}

bool isTriplt(int *arr, int requiredSum, int len)
{
  for (int i = 0; i < len - 2; i++)
  {
    if (isPair(arr, requiredSum - arr[i], i, len))
    {
      return true;
    }
  }
  return false;
}

int main()
{
  int arr[] = {2, 4, 6, 8, 11, 12, 16, 20};
  int sum = 2;

  cout << isTriplt(arr, sum, 8);
  return 0;
}