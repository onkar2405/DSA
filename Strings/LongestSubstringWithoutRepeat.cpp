#include <iostream>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
  int maxLen = 0;
  int st = 0;
  int itr = 0;
  map<char, int> mp;
  int tempLen = 0;
  while (itr < s.size())
  {
    char ch = s[itr];
    mp[ch]++;
    if (mp[ch] == 1)
    {
      tempLen++;
      maxLen = max(maxLen, tempLen);
    }
    else
    {
      while (st < itr)
      {
        if (mp[s[st]] > 1)
        {
          mp[s[st]]--;
          st++;
          break;
        }
        mp[s[st]] = 0;
        st++;
      }
      tempLen = itr - st + 1;
    }
    itr++;
  }

  return max(maxLen, tempLen);
}

int main()
{
  string str = "abcaabcded";
  cout << lengthOfLongestSubstring(str);
  return 0;
}