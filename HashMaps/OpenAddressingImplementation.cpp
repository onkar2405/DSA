/**
 * Consideration:
 *
 * -1 : empty cell
 * -2 : Deleted cell
 * Considering -1 and -2 are will never be keys.
 */

#include <iostream>
#include <algorithm>
using namespace std;

class MyHash
{
  int size;
  int *hashMap;

public:
  MyHash(int s) : size(s)
  {
    hashMap = new int[size];
    fill(hashMap, hashMap + size, -1);
  }

  void insert(int value)
  {
    int i = value % size;

    while (hashMap[i] != -1 && hashMap[i] != -2 && hashMap[i] != value)
    {
      /**
       * This is to iterate over full array size in a circularly starting from
       * index(i) to size-1 to i-1.
       */
      i = (i + 1) % size;
    }
    if (hashMap[i] == value)
    {
      cout << "\nKey already present.\n";
    }
    else
    {
      hashMap[i] = value;
    }
  }

  void erase(int value)
  {
    int index = value % size;

    if (hashMap[index] == value)
    {
      hashMap[index] = -2;
    }
    else
    {
      for (int i = index; i < size; i++)
      {
        if (hashMap[i] == value)
        {
          hashMap[i] = -2;
          break;
        }
      }
    }
    cout << "\nNumber not found";
  }

  void display()
  {
    cout << "\n Data in hashmap is: \n";

    for (size_t i = 0; i < size; i++)
    {
      cout << hashMap[i] << " ";
    }
  }
};

int main()
{
  MyHash myHash(10);

  myHash.insert(20);
  myHash.insert(20);
  myHash.insert(31);
  myHash.insert(32);
  myHash.insert(33);
  myHash.insert(34);
  myHash.insert(35);

  myHash.display();

  myHash.erase(34);
  myHash.erase(69);

  myHash.display();

  return 0;
}
