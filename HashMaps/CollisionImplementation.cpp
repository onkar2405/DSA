#include <iostream>
#include <list>
using namespace std;

int BUCKET = 7;

void insertElement(list<int> *table, int value)
{
  int index = value % BUCKET;
  table[index].push_back(value);
}

void removeElement(list<int> *table, int key)
{
  int index = key % BUCKET;
  table[index].remove(key);
}

void displayElements(list<int> *table)
{
  for (int i = 0; i < BUCKET; i++)
  {
    for (auto x : table[i])
    {
      cout << x << " ";
    }
    cout << "\n";
  }
}

bool searchElement(list<int> *table, int key)
{
  int index = key % BUCKET;
  for (auto x : table[index])
  {
    if (x == key)
    {
      return true;
    }
  }
  return false;
}

int main()
{
  list<int> *table = new list<int>[BUCKET];

  insertElement(table, 20);
  insertElement(table, 30);
  insertElement(table, 40);
  insertElement(table, 50);
  insertElement(table, 70);

  displayElements(table);

  cout << "After removing List is: \n";

  removeElement(table, 20);
  removeElement(table, 10);

  displayElements(table);

  cout << "Search result: " << searchElement(table, 70) << "\n";
  cout << "Search result: " << searchElement(table, 20);

  return 0;
}