#include <iostream>
using namespace std;

int leftMostRepeatingChar(string str)
{
  int arr[256];
  fill(arr, arr + 256, -1);
  int res = 10000000;

  for (int i = 0; i < str.length(); i++)
  {
    int charCount = arr[str[i]];
    if (charCount == -1)
    {
      arr[str[i]] = i;
    }
    else
    {
      res = min(res, arr[str[i]]);
    }
  }

  return res == 10000000 ? -1 : res;
}

int main()
{
  string str1 = "abcdefggf";

  cout << leftMostRepeatingChar(str1);

  return 0;
}