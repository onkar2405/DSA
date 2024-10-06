#include <iostream>
using namespace std;

int firstOccuranceRecursive(int *arr, int num, int low, int high)
{
  int middle = (low + high) / 2;
  if (low > high)
  {
    return -1;
  }
  if (arr[middle] > num)
  {
    return firstOccuranceRecursive(arr, num, low, middle - 1);
  }
  else if (arr[middle] < num)
  {
    return firstOccuranceRecursive(arr, num, middle + 1, high);
  }
  else
  {
    if (middle == 0 || arr[middle - 1] != arr[middle])
    {
      return middle;
    }
    else
    {
      return firstOccuranceRecursive(arr, num, low, middle - 1);
    }
  }
}

int firstOccuranceIterative(int *arr, int num, int len)
{
  int low = 0;
  int high = len - 1;

  while (low <= high)
  {
    int middle = (low + high) / 2;
    if (arr[middle] > num)
    {
      high = middle - 1;
    }
    else if (arr[middle] < num)
    {
      low = middle + 1;
    }
    else
    {
      if (middle == 0 || arr[middle - 1] != arr[middle])
      {
        return middle;
      }
      else
      {
        high = middle - 1;
      }
    }
  }

  return -1;
}

int main()
{

  int arr[] = {1, 4, 10, 10, 20, 20};
  int numberToFind = 20;

  cout << firstOccuranceRecursive(arr, numberToFind, 0, 6);
  cout << "\n"
       << firstOccuranceIterative(arr, numberToFind, 6);

  return 0;
}