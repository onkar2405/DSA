#include <iostream>
using namespace std;

void printSubsets(string str, int index = 0, string curr = "")
{

  if (index == str.length())
  {
    cout << curr << " ";
    return;
  }
  printSubsets(str, index + 1, curr + str[index]);
  printSubsets(str, index + 1, curr);
}

int main()
{

  string str = "abc";
  printSubsets(str);

  return 0;
}