#include <iostream>
#include <unordered_set>
using namespace std;

void displaySet(unordered_set<int> set)
{
  cout << "\n";
  for (auto i = set.begin(); i != set.end(); i++)
  {
    cout << *i << " ";
  }
}

int main()
{
  unordered_set<int> set;

  set.insert(10);
  set.insert(20);
  set.insert(30);
  set.insert(40);
  set.insert(50);
  set.insert(60);
  cout << "\nSize: " << set.size();

  displaySet(set);
  cout << "\nFind 10: " << *(set.find(10));
  cout << "\nCount 10: " << set.count(10);

  cout << "\nEmpty: " << set.empty();

  cout << "\nSize: " << set.size();
  cout << "\nErase: " << set.erase(10);

  set.clear();
  cout << "\nSize: " << set.size();

  return 0;
}