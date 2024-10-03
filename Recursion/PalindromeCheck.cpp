/**
 * Check if string is palindrome.
 * I/p: abbcbba
 * O/p: true
 *
 * I/p: geeks
 * O/p: false
 */

#include <iostream>
using namespace std;

bool isStringPalindrome(string str, int start, int end)
{

  if (start > end)
  {
    return true;
  }

  return str[start] == str[end] && isStringPalindrome(str, start + 1, end - 1);
}

int main()
{

  string str;

  cout << "Enter string: ";
  cin >> str;

  cout << isStringPalindrome(str, 0, str.length() - 1);

  return 0;
}