#include <iostream>
#include <vector>
using namespace std;

string reverseWords(string s)
{
  vector<string> words;
  if (s.length() == 0)
  {
    return s;
  }

  string temp = "";
  int length = 0;
  while (length < s.length())
  {
    if (s[length] == ' ')
    {
      if (temp.length() != 0)
      {
        words.push_back(temp);
      }
      temp = "";
    }
    else
    {
      temp.append(s[length]);
    }
    length++;
  }

  string newString;
  for (int i = words.size() - 1; i >= 0; i++)
  {
    if (i != 0)
    {
      newString.append()
    }
    else
    {
      newString.append(s[i]);
    }
  }

  return newString;
}

int main()
{
  cout << reverseWords("hello world");
  return 0;
}