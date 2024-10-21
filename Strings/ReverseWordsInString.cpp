#include <iostream>
#include <vector>
using namespace std;

void reverseWordsWithVector(string str)
{
  vector<string> temp;
  string str1;

  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == ' ')
    {
      temp.push_back(str1);
      str1 = "";
      continue;
    }
    str1.push_back(str[i]);
  }
  temp.push_back(str1);

  for (int i = temp.size() - 1; i >= 0; i--)
  {
    if (i != 0)
    {
      cout << temp[i] << " ";
    }
    else
    {
      cout << temp[i];
    }
  }
}

void reverseWord(string str, int start, int end)
{
  while (start <= end)
  {
    swap(str[start], str[end]);
    start++;
    end--;
  }
}

void reverString(string str)
{
  int start = 0;
  for (int i = 0; i < str.size(); i++)
  {
    if (str[i] == ' ')
    {
      reverseWord(str, start, i - 1);
      start = i + 1;
    }
  }

  reverseWord(str, start, str.size() - 1);
  reverseWord(str, 0, str.size() - 1);

  cout << str;
}

int main()
{
  string str = "I love Java";

  reverString(str);

  return 0;
}