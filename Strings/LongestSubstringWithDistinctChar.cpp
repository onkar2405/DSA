#include <iostream>
#include <vector>
using namespace std;

string longestSubstring(string str)
{
  string longest = "";

  for (int i = 0; i < str.length(); i++)
  {
    vector<bool> isVisited(256);
    string temp = "";
    temp.push_back(str[i]);
    isVisited[str[i]] = true;

    for (int j = i + 1; i < str.length(); j++)
    {
      if (isVisited[str[j]] == true)
      {
        break;
      }
      temp.push_back(str[j]);
      isVisited[str[j]] = true;
    }
    longest = longest.length() > temp.length() ? longest : temp;

    if (longest.length() >= str.length() - i - 1)
    {
      return longest;
    }
  }

  return longest;
}

int main()
{
  string str = "abcaabcded";
  cout << longestSubstring(str);
  return 0;
}