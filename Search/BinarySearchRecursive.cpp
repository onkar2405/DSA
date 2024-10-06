#include <iostream>
using namespace std;

int binarySearch(int *arr, int num, int low, int high)
{
  if (low > high)
  {
    return -1;
  }
  int middle = (low + high) / 2;

  if (arr[middle] == num)
  {
    return middle;
  }
  if (arr[middle] > num)
  {
    return binarySearch(arr, num, low, middle - 1);
  }
  else
  {
    return binarySearch(arr, num, middle + 1, high);
  }
}
