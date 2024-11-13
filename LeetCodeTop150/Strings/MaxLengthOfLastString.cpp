#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/length-of-last-word/?envType=study-plan-v2&envId=top-interview-150
 */
int lengthOfLastWord(string s)
{
  if (s.length() < 0)
    return 0;

  int i = s.length() - 1;
  while (i >= 0 && s[i] == ' ')
  {
    i--;
  }
  if (i < 0)
  {
    return 0;
  }
  int length = 0;
  while (i >= 0 && s[i] != ' ')
  {
    length++;
    i--;
  }

  return length;
}

int main()
{
  cout << lengthOfLastWord("a");
  return 0;
}