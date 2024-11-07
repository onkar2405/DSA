#include <iostream>
using namespace std;

/**
 * https://leetcode.com/problems/valid-palindrome/description/?envType=study-plan-v2&envId=top-interview-150
 */
bool isPalindrome(string s)
{
  int start = 0;
  int end = s.length() - 1;

  while (start <= end)
  {
    char firstChar = s[start];
    char lastChar = s[end];

    if (!isalnum(firstChar))
    {
      start++;
    }
    else if (!isalnum(lastChar))
    {
      end--;
    }
    else
    {
      if (tolower(firstChar) != tolower(lastChar))
      {
        return false;
      }
      start++;
      end--;
    }
  }
  return true;
}

int main()
{
  // string str = "A man, a plan, a canal: Panama";
  string str = "race a car";

  cout << isPalindrome(str);

  return 0;
}