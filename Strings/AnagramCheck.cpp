#include <iostream>
#include <unordered_map>
using namespace std;

bool checkIsAnagramWithMap(string str1, string str2)
{
  if (str1.length() != str2.length())
  {
    return false;
  }

  unordered_map<char, int> map1;
  unordered_map<char, int> map2;

  for (int i = 0; i < str1.size(); i++)
  {
    map1[str1[i]]++;
    map2[str2[i]]++;
  }

  for (auto it = map1.begin(); it != map1.end(); it++)
  {
    auto map2Ele = map2.find(it->first);
    if (map2Ele == map2.end() || map2Ele->second != it->second)
    {
      return false;
    }
    cout << map2Ele->first;
  }

  return true;
}

bool checkIsAnagram(string str1, string str2)
{
  if (str1.length() != str2.length())
  {
    return false;
  }

  int count[256] = {0};
  for (int i = 0; i < str1.size(); i++)
  {
    count[str1[i]]++;
    count[str2[i]]--;
  }

  for (int i = 0; i < 256; i++)
  {
    if (count[i] != 0)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  string str1 = "listen";
  string str2 = "silent";

  cout << checkIsAnagram(str1, str2);

  return 0;
}