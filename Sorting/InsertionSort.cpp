#include <iostream>
using namespace std;

void insertionSort(int *arr, int len)
{
  for (int i = 1; i < len; i++)
  {
    int key = arr[i];
    int j;
    for (j = i - 1; j >= 0 && arr[j] > key; j--)
    {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
  }

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {10, 5, 14, 3};
  insertionSort(arr, 4);
  return 0;
}
