#include <iostream>
using namespace std;

bool checkIfStringIsSubsequenceRecursive(string str1, string str2, int i = 0, int j = 0)
{
  if (j == str2.size())
    return true;
  if (i == str1.size())
    return false;

  if (str2[j] == str1[i])
  {
    return checkIfStringIsSubsequenceRecursive(str1, str2, i + 1, j + 1);
  }
  return checkIfStringIsSubsequenceRecursive(str1, str2, i + 1, j);
}

int checkIfStringIsSubsequence(string str1, string str2)
{
  int j = 0;
  for (int i = 0; i < str1.size() && j < str2.size(); i++)
  {
    if (str1[i] == str2[j])
    {
      j++;
    }
  }
  return j == str2.size();
}

int main()
{
  string str2 = "ab";
  string str1 = "abc";

  cout << checkIfStringIsSubsequence(str1, str2);

  cout << checkIfStringIsSubsequenceRecursive(str1, str2);

  return 0;
}