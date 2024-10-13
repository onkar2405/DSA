#include <iostream>
using namespace std;

void bubbleSortOptimized(int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    int isSwapped = false;
    for (int j = 0; j < len - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        isSwapped = true;
      }
    }
    if (!isSwapped)
    {
      break;
    }
  }

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
}

void bubbleSort(int *arr, int len)
{
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {50, 10, 2, 12, 8};
  int len = 5;

  bubbleSort(arr, len);

  return 0;
}