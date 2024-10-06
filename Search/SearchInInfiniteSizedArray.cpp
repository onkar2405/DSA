#include <iostream>
#include "BinarySearchRecursive.cpp"
using namespace std;

int infiniteArraySearch(int *infiniteArray, int num, int len)
{
  if (infiniteArray[0] == num)
  {
    return 0;
  }
  int i = 1;

  while (infiniteArray[i] <= num)
  {
    if (infiniteArray[i] == num)
    {
      return i;
    }
    i = i * 2;
  }

  return binarySearch(infiniteArray, num, (i / 2) + 1, i);
}

int main()
{
  int infiniteArray[] = {10, 20, 30, 40, 50, 60, 70};

  cout << infiniteArraySearch(infiniteArray, 80, 7);
  return 0;
}