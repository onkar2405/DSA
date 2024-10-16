#include <iostream>
using namespace std;

void printFreq(string str)
{
  int arr[26] = {0};

  for (int i = 0; i < str.length(); i++)
  {
    arr[str[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++)
  {
    if (arr[i] > 0)
    {
      cout << (char)(i + 'a') << ":" << arr[i] << "\n";
    }
  }
}

int main()
{
  string str = "geeksforgeeks";
  printFreq(str);
  return 0;
}