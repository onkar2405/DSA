#include <iostream>
#include <vector>
using namespace std;

string simplifyPath(string path)
    string simplifyPath(string path)
{
  vector<string> stack;
  int i = 0;
  while (i < path.size())
  {
    if (path[i] == '/')
    {
      i++;
      continue;
    }
    string temp = "";
    while (i < path.length() && path[i] != '/')
    {
      temp.push_back(path[i]);
      i++;
    }
    if (temp == ".")
    {
      continue;
    }
    else if (temp == "..")
    {
      if (!stack.empty())
      {
        stack.pop_back();
      }
    }
    else
    {
      temp = "/" + temp;
      stack.push_back(temp);
    }
    i++;
  }

  string str = "";
  if (!stack.size())
  {
    return "/";
  }

  for (int i = 0; i < stack.size(); i++)
  {
    str = str + stack[i];
  }

  return str;
}

int main()
{

  cout << simplifyPath("/../");
  return 0;
}