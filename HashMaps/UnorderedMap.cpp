#include <iostream>
#include <unordered_map>
using namespace std;

void display(unordered_map<string, int> map)
{
  for (auto x : map)
  {
    cout << x.first << ":" << x.second << " ";
  }
}

int main()
{

  unordered_map<string, int> map;

  map["gfg"] = 20;
  map["gfg"] = 25;
  map["onkar"] = 24;

  map.insert({"Vaidya", 1998});

  display(map);

  if (map.find("gfg") == map.end())
  {
    cout << "\nNOT FOUND";
  }
  else
  {
    cout << "\nFOUND";
  }

  return 0;
}