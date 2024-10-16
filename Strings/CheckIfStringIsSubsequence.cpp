#include <iostream>
using namespace std;

void checkIfStringIsSubsequenceRecursive(string str1, string str2, string subStr = "")
{
  if (subStr.compare(str1))
  {
    cout << "YES";
    return;
  }
  if (subStr.size() == str2.size())
  {
    cout << "NO";
    return;
  }

  for (int i = 0; i < str2.size(); i++)
  {
    checkIfStringIsSubsequenceRecursive(str1, str2, subStr);
    checkIfStringIsSubsequenceRecursive(str1, str2, subStr + str2[i]);
  }
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
  string str2 = "lmao";
  string str1 = "geeksforgeeks";

  cout << checkIfStringIsSubsequence(str1, str2);

  return 0;
}