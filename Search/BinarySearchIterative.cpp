#include <iostream>
using namespace std;

int binarySearch(int *arr, int num, int len)
{
  int low = 0;
  int high = len - 1;

  while (low <= high)
  {
    int middle = (low + high) / 2;
    if (arr[middle] == num)
    {
      return middle;
    }
    if (arr[middle] > num)
    {
      high = middle - 1;
    }
    else
    {
      low = middle + 1;
    }
  }

  return -1;
}

int main()
{

  int arr[] = {1, 4, 10, 11, 14, 50};
  int numberToFind = 50;

  cout << binarySearch(arr, numberToFind, 6);
  return 0;
}