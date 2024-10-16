#include <iostream>
using namespace std;

void palindromeCheck(string str)
{
  int start = 0;
  int end = str.size() - 1;

  while (start <= end)
  {
    if (str[start] != str[end])
    {
      cout << "String not palindrome!!\n";
      return;
    }
    start++;
    end--;
  }
  cout << "String is Palindrome.\n";
}

int main()
{
  string str = "abcdcba";
  string str1 = "onkar";
  palindromeCheck(str);
  palindromeCheck(str1);

  return 0;
}