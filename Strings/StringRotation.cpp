#include <iostream>
using namespace std;

bool stringRotationPossible(string str1, string str2)
{
  return str1.length() != str2.length() ? false : (str1 + str1).find(str2) != -1;
}

bool stringRotationPossibleNaive(string str1, string str2)
{
  if (str1.length() != str2.length())
  {
    return false;
  }

  int rotations = str1.length();

  while (rotations != 0)
  {
    if (str1 == str2)
    {
      return true;
    }
    char ch = str1[0];

    for (int i = 0; i < str1.length() - 1; i++)
    {
      str1[i] = str1[i + 1];
    }
    str1[str1.length() - 1] = ch;
    rotations--;
  }
  return false;
}

int main()
{
  string str1 = "ABCD";
  string str2 = "CDAB";

  cout << stringRotationPossible(str1, str2);

  return 0;
}