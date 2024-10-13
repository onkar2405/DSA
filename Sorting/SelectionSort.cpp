#include <iostream>
using namespace std;

void selectionSort(int *arr, int len)
{
  // 6 15 11 8
  for (int i = 0; i < len; i++)
  {
    int minElement = i;
    for (int j = i + 1; j < len; j++)
    {
      if (arr[j] < arr[minElement])
      {
        minElement = j;
      }
    }
    swap(arr[minElement], arr[i]);
  }

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {15, 6, 11, 8};

  selectionSort(arr, 4);

  return 0;
}