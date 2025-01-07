#include <iostream>
#include <unordered_map>
using namespace std;

/**
 * https://leetcode.com/problems/ransom-note/description/?envType=study-plan-v2&envId=top-interview-150
 */
bool canConstruct(string ransomNote, string magazine)
{

  if (ransomNote.length() > magazine.length())
  {
    return false;
  }

  unordered_map<char, int> mMap;

  for (char ch : magazine)
  {
    mMap[ch]++;
  }

  for (char ch : ransomNote)
  {
    if (mMap[ch] == 0)
    {
      return false;
    }
    mMap[ch]--;
  }

  return true;
}